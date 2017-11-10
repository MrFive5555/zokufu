#ifndef GENEALOGY_H_
#define GENEALOGY_H_

#include <ctime>
#include <climits>
#include <functional>
#include <string>
#include <map>
#include <memory>
#include <vector>

using namespace std;

/*
* Person是储存每个具体人信息的类
* 对错误或未定义的Person，name属性为空字符串
*/
class Person {
public:
    typedef enum {
        MALE,
        FEMALE
    } Gender;

    /*
    * 对错误或未定义的Date，所有时间都定为0
    */
    class Date {
    public:
        Date(int year, int month, int day) : year(year), month(month), day(day) {
            if (!isValid()) {
                year = month = day = 0;
            }
        };
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool setYear(int newYear);
        bool setMonth(int newMonth);
        bool setDay(int newDay);
    private:
        int year;
        int month;
        int day;
        bool isValid() const;
    };

    Person() : name(""), birthday(birthday), gender(gender) {};
    Person(string name, Date birthday, Gender gender) : name(name), birthday(birthday), gender(gender) {}
    string getName() const;
    Date getBirthday() const;
    Gender getGender() const;
    bool setName();
    bool setBirthday();
    bool setGender();
private:
    string name;
    Date birthday;
    Gender gender;
};

/*
* id号的类型
* 对错误或未定义的id，应赋值为UNDEFINE_ID
*/
typedef int id_t;
const id_t UNDEFINE_ID = INT_MAX;

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
class Genealogy {
public:
    /*
    * 输入：void
    * 输出：返回一个指向已创建的Genealogy指针
    * 说明：单例模式，使全局仅有一个Genealogy
    *       当实例被第一次创建的时候，读取已存在文件中的家谱
    */
    Genealogy* getInstance();

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
    id_t getId(const Person& person);
    Person& getPersonById(id_t id) const;

    /*
    * 输入：已存在的Person或id
    * 输出：对应的id或Person对象
    * 说明：当母亲节点为空时，返回默认构造的Person
    */
    Person& father(id_t id) const;
    Person& monther(id_t id) const;

    /*
    * 输入：已存在id
    * 输出：对应id父亲或母亲的id
    * 说明：当母亲节点为空时，返回UNDEFINE_ID
    */
    id_t getFather(id_t id) const;
    id_t getMonther(id_t id) const;

    /*
    * 输入：已存在id
    * 输出：对应id的兄弟（按大小排序），妻子（任意顺序），孩子（按大小排序）的vector集合
    * 说明：当母亲节点为空时，返回UNDEFINE_ID
    */
    vector<id_t> getBrother(id_t id) const;
    vector<id_t> getWift(id_t id) const;
    vector<id_t> getChild(id_t id) const;

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
    bool addChild(id_t fatherId, id_t motherId, id_t childId);

    /*
    * 输入：fatherId ：, id_t motherId, id_t childId
    * 输出：若输入的Person存在，返回true；若不存在，返回false
    * 说明：把输入的Person设置成树的根
    */
    bool removeChild(id_t id);

    /*
    * 输入：exec：对家谱内每一个成员执行exec函数
    * 输出：若输入的Person存在，返回true；若不存在，返回false
    * 说明：把输入的Person设置成树的根
    */
    void traverse(function<void(const id_t id)>exec);

    /*
    * 输入：void
    * 输出：void
    * 说明：把家谱按照特定的格式输出
    */
    void display() const;
private:
    Genealogy();

    class TreeNode {
        id_t id;
        shared_ptr<TreeNode> mother;
        shared_ptr<TreeNode> child;
        shared_ptr<TreeNode> brother;
    };
    map<id_t, Person&> idMap;
    shared_ptr<TreeNode> root;

    /*
    * 输入：void
    * 输出：一个新的id
    * 说明：每次把新的Person插入家谱时，需要往idMap里插入一个(id, Person)对，
    *       该函数用来生成一个未被使用的id号
    */
    id_t getNewId();
};
#endif // !GENEALOGY_H_
