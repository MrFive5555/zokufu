#include"storage.h"
#include"def.h"
#include"include.h"
using namespace std;
using namespace boost;
using namespace io; // extract names from csv.h
// local helper funcs
void personExist(id_type r,const idmap_t* p){
	if(p->find(r)==p->end())
		throw runtime_error(string()+"person with id "+to_string(r)+" doesn't exist");
}
template<typename g_t>
bool vertex_exist(id_type id,g_t g){
	return num_vertices(g)>id;
}
template<typename g_t>
bool exist_and_non_naked(id_type id,g_t g){
	return vertex_exist(id,g)&&degree(id,g)>0;
}
template<typename G>
void csv_into_graph(const char* fn,G& g){
	// not any verifying
	io::CSVReader<
		2, // column_count
		trim_chars<' ', '\t'>,
		no_quote_escape<','>,
		throw_on_overflow,
		single_and_empty_line_comment<'#'>
	>in(fn);
	in.read_header(io::ignore_extra_column,G_CSV_COL1,G_CSV_COL2);
	id_type id1,id2;
	while(in.read_row(id1,id2))
		add_edge(id1,id2,g);
}
template<typename G>
void to_csv(const char* fn,const G& g){
	ofstream ofs(fn);
	auto itp=edges(g);
	typedef typename graph_traits<G>::edge_descriptor E;
	ofs<<G_CSV_COL1<<","<<G_CSV_COL2<<endl;
	for_each(itp.first,itp.second,[&](const E e){
		ofs<<source(e,g)<<","<<target(e,g)<<endl;
	});
	ofs.close();
}
template<typename G>
void debug_graph(const G& g){
	cout<<"-------------"<<endl;
	typedef typename graph_traits<G>::edge_iterator EI;
	typedef typename graph_traits<G>::edge_descriptor E;
	const std::pair<EI, EI> itp=edges(g);
	for_each(itp.first,itp.second,[&](const E e){
		cout<<source(e,g)<<" -> "<<target(e,g)<<endl;
	});
	cout<<"-------------"<<endl;
}
Storage* Storage::instance=nullptr;
Storage* Storage::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new Storage;
  return instance;
}
void Storage::init(){
	add_vertex(tree);
}
namespace tmp{
// gvars
const idmap_t* theft=nullptr;
set<id_type> fellow;
// writer class templates
template<class G>
class undefault_writer {
public:
  undefault_writer()=delete;
  undefault_writer(G& g_):g(g_){}
  void operator()(std::ostream&) const {
  }
  template <class VorE>
  void operator()(std::ostream& os, const VorE& x) const {
  	personExist(x,theft);
  	os<<"["
  		<<"label="
  			<<"\""
  				<<x
  				<<" "
  				<<theft->at(x).name
  				<<" "
  				<<degree(x,g)
  			<<"\""
  		<<","
  		<<"color="<<(theft->at(x).gender==FEMALE?"red":"blue")
  		<<","
  		<<"style="<<(degree(x,g)==0?"invis":"solid")
  		<<"]";

  }
private:
  const G& g;
};
template<class G>
class another_writer {
public:
  another_writer()=delete;
  another_writer(G& g_):g(g_){}
  void operator()(std::ostream&) const {
  }
  template <class VorE>
  void operator()(std::ostream& os, const VorE& x) const {
  	personExist(x,theft);
  	os<<"["
	  		<<"label="
	  			<<"\""
	  				<<x
	  				<<" "
	  				<<theft->at(x).name
	  			<<"\""
	  		<<","
	  		<<"style="<<(degree(x,g)==0?"invis":(fellow.find(x)==fellow.end()?"dashed":"solid"))
  		<<"]";

  }
private:
  const G& g;
};
} // end namespace tmp
void display_dot(const string dotfile){
  string noext(dotfile);
  while(noext.back()!='.')
    noext.pop_back();
  system((string()+"dot -Tsvg -O "+dotfile).c_str());
  // sleep(1);
  system((string()+"chromium-browser "+dotfile+".svg").c_str());
  // sleep(1);
}
void Storage::display()const{
	// write graphviz-dot with customized label writer
	// compile graphviz-dot to svg
	// invoke chromium-browser to reander svg
	tmp::theft=&idMap;
	ofstream ofsS[]={
		ofstream(MATE_PRINT),
		ofstream(TREE_PRINT),
		ofstream(RAIN_PRINT),
		ofstream(NTR_PRINT)
	};
	cout<<"Writing dot files..."<<endl;
	write_graphviz(ofsS[0],mate,tmp::undefault_writer<const Ugraph&>(mate));
	write_graphviz(ofsS[1],tree,tmp::undefault_writer<const Digraph&>(tree));
	write_graphviz(ofsS[2],rain,tmp::undefault_writer<const Digraph&>(rain));

	Digraph ntr;
	// const std::pair<EI, EI> itp=edges(g);
	// for_each(itp.first,itp.second,[&](const E e){
	// 	cout<<source(e,g)<<" -> "<<target(e,g)<<endl;
	// });
	typedef typename graph_traits<Digraph>::edge_iterator EI;
	typedef typename graph_traits<Digraph>::edge_descriptor E;
	const pair<EI,EI> itp=edges(tree);
	for_each(itp.first,itp.second,[&](const E e){
		const auto s=source(e,tree);
		const auto t=target(e,tree);
		add_edge(s,t,ntr);
		tmp::fellow.insert(s);
		tmp::fellow.insert(t);
	});
	const auto jtp=edges(rain);
	for_each(jtp.first,jtp.second,[&](const E e){
		const auto s=source(e,rain);
		const auto t=target(e,rain);
		add_edge(s,t,ntr);
	});
	write_graphviz(ofsS[3],ntr,tmp::another_writer<const Digraph&>(ntr));
	for(auto& r:ofsS)
		r.close();
	for(auto i:{MATE_PRINT,TREE_PRINT,RAIN_PRINT,NTR_PRINT})
		display_dot(i);
}
void Storage::attach_to_root(id_type r){
	personExist(r,&idMap);
	if(vertex_exist(ROOT,tree)&&out_degree(ROOT,tree)!=0)
		throw runtime_error("Root cannot have 2 subsprings");
	if(exist_and_non_naked(r,mate)||exist_and_non_naked(r,tree)||exist_and_non_naked(r,rain))
		throw runtime_error("You can only attach a bachelor(no wife no son) to root");
	add_edge(ROOT,r,tree);
}
void Storage::mate_might_birth(const vector<id_type> v){
	// size
	if(v.size()<2)
		throw runtime_error(">=2 people needed");
	// root is infertile
	if(v[0]==0||v[1]==0)
		throw runtime_error("root can't have children");
	// exist
	for(auto r:v){
		personExist(r,&idMap);
	}
	const id_type master=v[0];
	const id_type slave=v[1];
	if(!vertex_exist(master,tree)||in_degree(master,tree)<=0)
		throw runtime_error("The first person with isn't part of the family.");
	if(vertex_exist(slave,tree)&&in_degree(slave,tree)>0){
		throw runtime_error("Second person is already in the family, incest forbidden");
	}
	// add mate
	add_edge(master,slave,mate);
	for(size_t i=2;i!=v.size();++i){
		// check claimed child
		// if(num_vertices(tree)>v[i] && in_degree(v[i],tree)>0)
		if(vertex_exist(v[i],tree) && in_degree(v[i],tree)>0)
			throw runtime_error(string()+"The child with id "+to_string(i)+" already has parent(s)");
		add_edge(master,v[i],tree);
		add_edge(slave,v[i],rain);
	}
}
void Storage::load(){
	/*
	* read person file to idMap (immutable)
	* read relationship file to g
	*/
	io::CSVReader<
		9, // column_count
		trim_chars<' ', '\t'>,
		// no_quote_escape<','>,
		double_quote_escape<',', '\"'>,
		throw_on_overflow,
		// no_comment,
		single_and_empty_line_comment<'#'>
	>in(PERSON_STORAGE);
	in.read_header(io::ignore_extra_column,"id", "name","gender","birth_year","birth_month","birth_day","death_year","death_month","death_day");
	id_type id;
	string name,gender;
	date_t birth_year,birth_month,birth_day;
	date_t death_year,death_month,death_day;
	while(in.read_row(id,name,gender,birth_year,birth_month,birth_day,death_year,death_month,death_day)){
		if(idMap.find(id)!=idMap.end())
			throw runtime_error("Duplicate id detected");
		// idMap[id]={name,gender,birth_year,birth_month,birth_day,death_year,death_month,death_day};
		Person p{name,gender,birth_year,birth_month,birth_day,death_year,death_month,death_day};
		idMap.emplace(id,p);
	}
	// ifstream ifsS[]{ifstream(MATE_STORAGE), ifstream(TREE_STORAGE), ifstream(RAIN_STORAGE)};
	csv_into_graph(MATE_STORAGE,mate);
	csv_into_graph(TREE_STORAGE,tree);
	csv_into_graph(RAIN_STORAGE,rain);
	// edges(mate);
	// debug_graph(mate);
	// debug_graph(tree);
	// debug_graph(rain);
  // for(auto& r:ifsS)
  	// r.close();
}

// template <class Name>
template <typename Graph>
class my_vertex_writer {
public:
  my_vertex_writer(Graph& g) : g_(g) {}

  template <typename Vertex>
  void operator()(std::ostream& out, const Vertex& v) const {
       // pseudo-code!
       if (0 == boost::size(in_edges(v, g_)))
          out << "[style=\"invis\"]";
  }
private:
  Graph& g_;
};
// write
void Storage::sync(){
	/*
	* 	write mate, tree to corresponding files
	*/
	// ofstream ofsS[]{ofstream(MATE_STORAGE), ofstream(TREE_STORAGE), ofstream(RAIN_STORAGE)};
	// write 3 csv graphs
  // for(auto& r:ofsS)
  // 	r.close();
	to_csv(MATE_STORAGE,mate);
	to_csv(TREE_STORAGE,tree);
	to_csv(RAIN_STORAGE,rain);
}
// new, init, read
Storage::Storage()=default;

