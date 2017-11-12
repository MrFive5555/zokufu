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
  /*
  * 输入：void
  * 输出：返回一个指向已创建的storage指针
  * 说明：单例模式，使全局仅有一个storage
  *       当实例被第一次创建的时候，读取已存在文件中的家谱
  */
  static storage* getInstance();

  /*
  * 输入：void
  * 输出：void
  * 说明：read 2 files
  */
  void load();
  
  /*
  * 输入：void
  * 输出：void
  * 说明：把家谱当前状态写入文件
  */
  void sync();

  /*
  * size of vec
  *  if 2, mate them
  *  if >=3, add children
  * 
  * 
  * 
  * 
  */
  void mate_might_birth(vector<id_type>);
  // void mate_might_birth();

  /*
  * 输入：fatherId ：, id_type motherId, id_type childId
  * 输出：若输入的Person存在，返回true；若不存在，返回false
  * 说明：把输入的Person设置成树的根
  */
  bool removeChild(id_type id);

  /*
  * 输入：exec：对家谱内每一个成员执行exec函数
  * 输出：若输入的Person存在，返回true；若不存在，返回false
  * 说明：把输入的Person设置成树的根
  */
  // void traverse(function<void(const id_type id)>exec);

  /*
  * 输入：void
  * 输出：void
  * 说明：把家谱按照特定的格式输出
  */
  void display() const;

  /*
  * 输入：person
  * 输出：void
  * 说明：apply for a new id, add the person to map
  */
  void addPerson(const Person);
  void init();
private:
  // singleton
  storage();
  id_type getNewId()const;
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
