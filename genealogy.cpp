#include"person.h"
#include"genealogy.h"
// Function implementations are in order of dependency,
// not following the order in header.
Genealogy::Genealogy(){
  vertex_descriptor vd=add_vertex(root);
}
Genealogy* Genealogy::getInstance(){
  // We never release the pointer. Leakage is ok.
  if(!instance)
    instance=new Genealogy;
  return instance;
}
// void Genealogy::sync();
// id_t Genealogy::getId(const Person& person);
// Person& Genealogy::getPersonById(id_t id) const;
// Person& Genealogy::father(id_t id) const;
// Person& Genealogy::monther(id_t id) const;
// id_t Genealogy::getFather(id_t id) const;
// id_t Genealogy::getMonther(id_t id) const;
// vector<id_t> Genealogy::getBrother(id_t id) const;
// vector<id_t> Genealogy::getWife(id_t id) const;
// vector<id_t> Genealogy::getChild(id_t id) const;
// bool Genealogy::addRoot(const Person& grandFather);
// bool Genealogy::addChild(id_t fatherId, id_t motherId, id_t childId);
// bool Genealogy::removeChild(id_t id);
// void Genealogy::traverse(function<void(const id_t id)>exec);
// void Genealogy::display() const;
// id_t  Genealogy::getNewId();


