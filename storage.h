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
typedef int id_type;
const id_type UNDEFINE_ID = INT_MAX;

typedef int edge_weight_property_t;
typedef adjacency_list<
  vecS, // OutEdgeList
  vecS, // VertexList
  bidirectionalS, // Directed
  no_property, // VertexProperties
  property<edge_weight_t, edge_weight_property_t>, // EdgeProperties
  no_property, // GraphProperties
  listS // EdgeList
>Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef std::pair<int,int> E;
/*
* 在家谱Genalogy中，所有已加入家谱中的Person都将获得一个唯一的
* 的id，使用id可以查询到具体某一个Person
* ======================================================
* 数据结构：采用一种类树的结构。
* 树的某个节点有三个指针：一个指向他的兄弟，一个指向他的孩子，另一个指向自己的母亲。
*     由于采用了母亲指针的方式，事实上这个家谱不是一棵严格意义上的树，
*     但如果把所有节点的母亲指针去掉，就是一棵完整的树了。
*
* 对某个给定的节点，要查找对应关系的方法：
* 父亲：遍历二叉树，直到找到孩子为给定节点的节点，为给定节点的父亲
* 母亲：直接访问母亲指针对应的节点
* 兄弟：得到父亲节点，并得到父亲所有的孩子
* 孩子：遍历孩子指针及孩子的兄弟
* 妻子：遍历所有的孩子，所有孩子母亲的集合，就是给定节点的妻子
*
*/
class storage {
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
  * 说明：把家谱当前状态写入文件
  */
  void sync();

  /*
  * 输入：已存在的Person或id
  * 输出：对应的id或Person对象
  * 说明：当需要查询的Person不存在时，返回UNDEFINE_ID
  *       当需要查询的id不存在时，返回一个默认构造的Person
  */
  id_type getId(const Person& person);
  Person& getPersonById(id_type id) const;

  /*
  * 输入：已存在的Person或id
  * 输出：对应的id或Person对象
  * 说明：当母亲节点为空时，返回默认构造的Person
  */
  Person& father(id_type id) const;
  Person& monther(id_type id) const;

  /*
  * 输入：已存在id
  * 输出：对应id父亲或母亲的id
  * 说明：当母亲节点为空时，返回UNDEFINE_ID
  */
  id_type getFather(id_type id) const;
  id_type getMonther(id_type id) const;

  /*
  * 输入：已存在id
  * 输出：对应id的兄弟（按大小排序），妻子（任意顺序），孩子（按大小排序）的vector集合
  * 说明：当母亲节点为空时，返回UNDEFINE_ID
  */
  vector<id_type> getBrother(id_type id) const;
  vector<id_type> getWife(id_type id) const;
  vector<id_type> getChild(id_type id) const;

  /*
  * 输入：已存在的一个Person
  * 输出：若输入的Person存在，返回true；若不存在，返回false
  * 说明：把输入的Person设置成树的根
  */
  bool addRoot(const Person& grandFather);

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
private:
// singleton
  storage();
  static storage* instance;
  // the following two things involves file operation
  map<id_type, Person&> idMap;
  Graph g;

  /*
  * 输入：void
  * 输出：一个新的id
  * 说明：每次把新的Person插入家谱时，需要往idMap里插入一个(id, Person)对，
  *       该函数用来生成一个未被使用的id号
  */
  id_type getNewId();
};
// singleton
storage* storage::instance=nullptr;
#endif // !GENEALOGY_H_
