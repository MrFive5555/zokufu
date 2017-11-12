#ifndef GENEALOGY_H_
#define GENEALOGY_H_

#include <ctime>
#include <climits>
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "main.h"

using namespace std;
using namespace boost;

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
  void sync()const;

  /*
  * 输入：fatherId：父亲的id
  *       motherId：母亲的id
  *       childId需要插入孩子的id
  * 输出：若其中一个id不存在或id已在家谱中，返回false；否则返回true
  * 说明：childId对应的
  */
  bool addChild(id_type fatherId, id_type motherId, id_type childId);

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
  void traverse(function<void(const id_type id)>exec);

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
  // void init();
private:
  // singleton
  storage();
  id_type getNewId()const;
// data members
private:
  static storage* instance;
  // the following two things involves file operation
  Graph g;
  map<id_type,const Person> idMap;

  /*
  * 输入：void
  * 输出：一个新的id
  * 说明：每次把新的Person插入家谱时，需要往idMap里插入一个(id, Person)对，
  *       该函数用来生成一个未被使用的id号
  */
  bool dirty;
  // id_type max_id;
};
#endif // !GENEALOGY_H_
