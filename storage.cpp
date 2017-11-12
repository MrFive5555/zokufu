#include<stdexcept>
#include<boost/graph/graph_traits.hpp>
#include"person.h"
#include"storage.h"


using namespace std;
using namespace boost;


// singleton jibberjabber
storage* storage::instance=nullptr;
storage* storage::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new storage;
  return instance;
}

// new, init, read
storage::storage():g(),idMap(){}
// void storage::init(){
// 	Graph h;
// 	g=h;
// 	sync();
// }
void storage::load(){
	/*
	* read person file to idMap
	* deduct max_id from person file
	* read relationship file to g
	*/
}

// write
void storage::sync()const{
	/*
	* 	write idMap to person file
	* 	write g to relationship file
	*/

}
id_type  storage::getNewId()const{
	if(idMap.empty())
		return 0;
	return idMap.rbegin()->first+1;
}
void storage::addPerson(const Person p){
	// idMap[getNewId()]=p;
	idMap.emplace(getNewId(),p);
}
// id_t storage::getId(const Person& person);
const Person& storage::getPersonById(id_type id) const{
	if(idMap.find(id)==idMap.end())
		throw runtime_error("This id does not refer to any person. A.K.A the person doesn't exist");
	return idMap.at(id);
}
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

}


