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
storage::storage():hierarchy(),mate(),idMap(){}
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
	ifstream h(HIERARCHY_RELATIONSHIP_FILENAME);
	ifstream m(MATE_RELATIONSHIP_FILENAME);
	dynamic_properties dp(ignore_other_properties);
  read_graphviz(h,hierarchy,dp);
  read_graphviz(m,mate,dp);
  h.close();
  m.close();
}

// write
void storage::sync(){
	/*
	* 	write mate, hierarchy to corresponding files
	*/
	ofstream h(HIERARCHY_RELATIONSHIP_FILENAME);
	ofstream m(MATE_RELATIONSHIP_FILENAME);
	// cout<<"syncing"<<endl;
	// add_edge(0,5,hierarchy);
	// ofstream h("hierarchy.dot");
  write_graphviz(h,hierarchy);
  write_graphviz(m,mate);
  h.close();
  m.close();
}
void storage::mate_might_birth(const vector<id_type> v){
	// check incest
	// add mate
	// add hierarchy
	// check size

	if(v.size()<2)
		throw runtime_error(">=2 people needed");
	// check gender
	auto gpair=std::tie(idMap.at(v[0]).gender,idMap.at(v[1]).gender);
	if(gpair!=make_tuple(FEMALE,MALE)&&gpair!=make_tuple(MALE,FEMALE))
		throw runtime_error("No homosexuality please");
	add_edge(v[0],v[1],mate);
	for(size_t i=2;i!=v.size();++i){
		// check claimed child
		if(num_vertices(hierarchy)>v[i] && in_degree(v[i],hierarchy)>0)
			throw runtime_error(string()+"The child with id "+to_string(i)+" already has parent(s)");
		add_edge(v[0],v[i],hierarchy);
		add_edge(v[1],v[i],hierarchy);
	}

}
// id_t storage::getId(const Person& person);
// const Person& storage::getPersonById(id_type id) const{
// 	if(idMap.find(id)==idMap.end())
// 		throw runtime_error("This id does not refer to any person. A.K.A the person doesn't exist");
// 	return idMap.at(id);
// }
// Person& storage::father(id_t id) const;
// Person& storage::monther(id_t id) const;
// id_t storage::getFather(id_t id) const;
// id_t storage::getMonther(id_t id) const;
// vector<id_t> storage::getBrother(id_t id) const;
// vector<id_t> storage::getWife(id_t id) const;
// vector<id_t> storage::getChild(id_t id) const;
// bool storage::addRoot(const Person& grandFather);
// bool storage::addChild(id_t fatherId, id_t motherId, id_t childId);
// bool storage::removeChild(id_t id);
// void storage::traverse(function<void(const id_t id)>exec);
void storage::display() const{
  display_dot(HIERARCHY_RELATIONSHIP_FILENAME);
  display_dot(MATE_RELATIONSHIP_FILENAME);
}


