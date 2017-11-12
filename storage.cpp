#include"person.h"
#include"storage.h"
#include<boost/graph/graph_traits.hpp>
#define HUSBAND_WIFE_WEIGHT 1
#define HUSBAND_WIFE_COLOR ""
#define WIFE_SUBSPRING_WEIGHT 2
#define WIFE_SUBSPRING_COLOR ""
using namespace std;
using namespace boost;
// Function implementations are in order of dependency,
// not following the order in header.
storage::storage():g(){
  // Graph::vertex_descriptor vd=add_vertex(root);
}
storage* storage::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new storage;
  return instance;
}
// void storage::sync();
// id_t storage::getId(const Person& person);
// Person& storage::getPersonById(id_t id) const;
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
// void storage::display() const;
// id_t  storage::getNewId();


