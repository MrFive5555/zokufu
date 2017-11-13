#ifndef STORAGE_H
#define STORAGE_H
#include "main.h"

/*
* id号的类型
* 对错误或未定义的id，应赋值为UNDEFINE_ID
*/

/* 
* Due to the following error:
*
*   /usr/include/x86_64-linux-gnu/sys/types.h:104:16: note: previous declaration as ‘typedef __id_t id_t’
*    typedef __id_t id_t;
*
* I have to change this type name ( "id_t" -> "id_type" )
*/

class storage {
// methods
public:
  static storage* getInstance();
// interface
// use the first letter as CLI parameter
  void init();
  // void display() const;
  // a new member which is directly(temporarily) attached to root
  // divide_and_conqueror, combine later
  void attach_to_root(id_type id);
  void mate_might_birth(vector<id_type>);
// non-interface
  void load();
  void sync();
private:
  // singleton
  storage();
  id_type getNewId()const;
  void personExist(id_type)const;
// data members
private:
  static storage* instance;
  // the following two things involves file operation
  Ugraph mate;
  Digraph tree;
  Digraph rain;
  map<id_type,const Person> idMap;

  /*
  * 输入：void
  * 输出：一个新的id
  * 说明：每次把新的Person插入家谱时，需要往idMap里插入一个(id, Person)对，
  *       该函数用来生成一个未被使用的id号
  */
  // bool dirty;
  // id_type max_id;
};
#endif // !GENEALOGY_H_
