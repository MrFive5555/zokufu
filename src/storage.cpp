#include"main.h"
#include"person.h"
#include"storage.h"

using namespace std;
using namespace boost;
using namespace io; // extract names from csv.h

template<typename g_t>
bool vertex_exist(id_type id,g_t g){
	return num_vertices(g)>id;
}

template<typename g_t>
bool exist_and_non_naked(id_type id,g_t g){
	return vertex_exist(id,g)&&degree(id,g)>0;
}

// singleton jibberjabber
storage* storage::instance=nullptr;
storage* storage::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new storage;
  return instance;
}
void storage::init(){
	// add_edge(0,1,tree);
	add_vertex(tree);
}
void storage::display() const{
	for(auto& r:{MATE_FILENAME,TREE_FILENAME,RAIN_FILENAME})
		display_dot(r);
}
void storage::attach_to_root(id_type r){
	personExist(r);
	// if(
	// 	(vertex_exist(mate,r)&&degree(r,mate)!=0) ||
	// 	(vertex_exist(tree,r)&&degree(r,mate)!=0) ||
	// 	(vertex_exist(rain,r)&&degree(r,mate)!=0)
	// )
	if(exist_and_non_naked(r,mate)||exist_and_non_naked(r,tree)||exist_and_non_naked(r,rain))
		throw runtime_error("You can only attach a bachelor(no wife no son) to root");
	add_edge(ROOT,r,tree);
}
void storage::mate_might_birth(const vector<id_type> v){
	// size
	if(v.size()<2)
		throw runtime_error(">=2 people needed");
	// root is infertile
	if(v[0]==0||v[1]==0)
		throw runtime_error("root can't have children");
	// exist
	for(auto r:v){
		personExist(r);
	}
	const id_type master=v[0];
	const id_type slave=v[1];
	if(!vertex_exist(master,tree)||in_degree(master,tree)<=0)
		throw runtime_error("The first person with isn't part of the family.");
	if(vertex_exist(slave,tree)||in_degree(slave,tree)>0)
		throw runtime_error("Second person is already in the family, incest forbidden");
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
void storage::load(){
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
	>in(PERSON_FILNAME);
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
	ifstream ifsS[]{ifstream(MATE_FILENAME), ifstream(TREE_FILENAME), ifstream(RAIN_FILENAME)};
	dynamic_properties dp(ignore_other_properties);
  read_graphviz(ifsS[0],mate,dp);
  read_graphviz(ifsS[1],tree,dp);
  read_graphviz(ifsS[2],rain,dp);
  for(auto& r:ifsS)
  	r.close();
}

// write
void storage::sync(){
	/*
	* 	write mate, tree to corresponding files
	*/
	// add_edge(0,1,tree);
	ofstream ofsS[]{ofstream(MATE_FILENAME), ofstream(TREE_FILENAME), ofstream(RAIN_FILENAME)};
  write_graphviz(ofsS[0],mate);
  write_graphviz(ofsS[1],tree);
  write_graphviz(ofsS[2],rain);
  for(auto& r:ofsS)
  	r.close();
  // person?
}
void storage::personExist(id_type r)const{
	if(idMap.find(r)==idMap.end())
		throw runtime_error(string()+"person with id "+to_string(r)+" doesn't exist");
}

// new, init, read
storage::storage()=default;

