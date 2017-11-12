#include"main.h"
#include"person.h"
#include"storage.h"

// #include"read_graphviz_new.cpp"


using namespace std;
using namespace boost;
using namespace io;


// singleton jibberjabber
storage* storage::instance=nullptr;
storage* storage::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new storage;
  return instance;
}

// new, init, read
storage::storage():tree(),mate(),idMap(){}
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
	ifstream h(TREE_FILENAME);
	ifstream m(MATE_FILENAME);
	dynamic_properties dp(ignore_other_properties);
  read_graphviz(h,tree,dp);
  read_graphviz(m,mate,dp);
  h.close();
  m.close();
}

// write
void storage::sync(){
	/*
	* 	write mate, tree to corresponding files
	*/
	ofstream m(MATE_FILENAME);
	ofstream t(TREE_FILENAME);
	ofstream r(RAIN_FILENAME);
	// cout<<"syncing"<<endl;
	// add_edge(0,5,tree);
	// ofstream h("tree.dot");
  write_graphviz(m,mate);
  write_graphviz(t,tree);
  write_graphviz(r,rain);
  m.close();
  t.close();
  r.close();
}
void storage::init(){
	add_edge(0,1,tree);
}
void storage::mate_might_birth(vector<id_type> v){
	// add mate
	// add tree

	// root is infertile
	if(v[0]==0||v[1]==0)
		throw runtime_error("root can't have children");
	// size
	if(v.size()<2)
		throw runtime_error(">=2 people needed");
	// exist
	for(auto r:v){
		if(idMap.find(r)==idMap.end())
			throw runtime_error(string()+"person with id "+to_string(r)+" doesn't exist");
	}
	// switch, father goes first
	if(idMap.at(v[0]).gender==FEMALE)
		std::swap(v[0],v[1]);
	const id_type father=v[0];
	const id_type mother=v[1];
	// check gender
	if(std::tie(idMap.at(father).gender,idMap.at(mother).gender)!=make_tuple(MALE,FEMALE))
		throw runtime_error("No homosexuality please");
	// incest
	if(in_degree(father,tree)>0&&in_degree(mother,tree)>0)
		throw runtime_error("No incest!");
	// add mate
	add_edge(father,mother,mate);
	for(size_t i=2;i!=v.size();++i){
		// check claimed child
		if(num_vertices(tree)>v[i] && in_degree(v[i],tree)>0)
			throw runtime_error(string()+"The child with id "+to_string(i)+" already has parent(s)");
		add_edge(father,v[i],tree);
		add_edge(mother,v[i],rain);
	}
}
void storage::display() const{
  display_dot(TREE_FILENAME);
  display_dot(MATE_FILENAME);
}


