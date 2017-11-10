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
* Person�Ǵ���ÿ����������Ϣ����
* �Դ����δ�����Person��name����Ϊ���ַ���
*/
class Person {
public:
    typedef enum {
        MALE,
        FEMALE
    } Gender;

    /*
    * �Դ����δ�����Date������ʱ�䶼��Ϊ0
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
* id�ŵ�����
* �Դ����δ�����id��Ӧ��ֵΪUNDEFINE_ID
*/
typedef int id_t;
const id_t UNDEFINE_ID = INT_MAX;

/*
* �ڼ���Genalogy�У������Ѽ�������е�Person�������һ��Ψһ��
* ��id��ʹ��id���Բ�ѯ������ĳһ��Person
* ======================================================
* ���ݽṹ������һ�������Ľṹ��
* ����ĳ���ڵ�������ָ�룺һ��ָ�������ֵܣ�һ��ָ�����ĺ��ӣ���һ��ָ���Լ���ĸ�ס�
*     ���ڲ�����ĸ��ָ��ķ�ʽ����ʵ��������ײ���һ���ϸ������ϵ�����
*     ����������нڵ��ĸ��ָ��ȥ��������һ�����������ˡ�
*
* ��ĳ�������Ľڵ㣬Ҫ���Ҷ�Ӧ��ϵ�ķ�����
* ���ף�������������ֱ���ҵ�����Ϊ�����ڵ�Ľڵ㣬Ϊ�����ڵ�ĸ���
* ĸ�ף�ֱ�ӷ���ĸ��ָ���Ӧ�Ľڵ�
* �ֵܣ��õ����׽ڵ㣬���õ��������еĺ���
* ���ӣ���������ָ�뼰���ӵ��ֵ�
* ���ӣ��������еĺ��ӣ����к���ĸ�׵ļ��ϣ����Ǹ����ڵ������
*
*/
class Genealogy {
public:
    /*
    * ���룺void
    * ���������һ��ָ���Ѵ�����Genealogyָ��
    * ˵��������ģʽ��ʹȫ�ֽ���һ��Genealogy
    *       ��ʵ������һ�δ�����ʱ�򣬶�ȡ�Ѵ����ļ��еļ���
    */
    Genealogy* getInstance();

    /*
    * ���룺void
    * �����void
    * ˵�����Ѽ��׵�ǰ״̬д���ļ�
    */
    void sync();

    /*
    * ���룺�Ѵ��ڵ�Person��id
    * �������Ӧ��id��Person����
    * ˵��������Ҫ��ѯ��Person������ʱ������UNDEFINE_ID
    *       ����Ҫ��ѯ��id������ʱ������һ��Ĭ�Ϲ����Person
    */
    id_t getId(const Person& person);
    Person& getPersonById(id_t id) const;

    /*
    * ���룺�Ѵ��ڵ�Person��id
    * �������Ӧ��id��Person����
    * ˵������ĸ�׽ڵ�Ϊ��ʱ������Ĭ�Ϲ����Person
    */
    Person& father(id_t id) const;
    Person& monther(id_t id) const;

    /*
    * ���룺�Ѵ���id
    * �������Ӧid���׻�ĸ�׵�id
    * ˵������ĸ�׽ڵ�Ϊ��ʱ������UNDEFINE_ID
    */
    id_t getFather(id_t id) const;
    id_t getMonther(id_t id) const;

    /*
    * ���룺�Ѵ���id
    * �������Ӧid���ֵܣ�����С���򣩣����ӣ�����˳�򣩣����ӣ�����С���򣩵�vector����
    * ˵������ĸ�׽ڵ�Ϊ��ʱ������UNDEFINE_ID
    */
    vector<id_t> getBrother(id_t id) const;
    vector<id_t> getWift(id_t id) const;
    vector<id_t> getChild(id_t id) const;

    /*
    * ���룺�Ѵ��ڵ�һ��Person
    * ������������Person���ڣ�����true���������ڣ�����false
    * ˵�����������Person���ó����ĸ�
    */
    bool addRoot(const Person& grandFather);

    /*
    * ���룺fatherId�����׵�id
    *       motherId��ĸ�׵�id
    *       childId��Ҫ���뺢�ӵ�id
    * �����������һ��id�����ڻ�id���ڼ����У�����false�����򷵻�true
    * ˵����childId��Ӧ��
    */
    bool addChild(id_t fatherId, id_t motherId, id_t childId);

    /*
    * ���룺fatherId ��, id_t motherId, id_t childId
    * ������������Person���ڣ�����true���������ڣ�����false
    * ˵�����������Person���ó����ĸ�
    */
    bool removeChild(id_t id);

    /*
    * ���룺exec���Լ�����ÿһ����Աִ��exec����
    * ������������Person���ڣ�����true���������ڣ�����false
    * ˵�����������Person���ó����ĸ�
    */
    void traverse(function<void(const id_t id)>exec);

    /*
    * ���룺void
    * �����void
    * ˵�����Ѽ��װ����ض��ĸ�ʽ���
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
    * ���룺void
    * �����һ���µ�id
    * ˵����ÿ�ΰ��µ�Person�������ʱ����Ҫ��idMap�����һ��(id, Person)�ԣ�
    *       �ú�����������һ��δ��ʹ�õ�id��
    */
    id_t getNewId();
};
#endif // !GENEALOGY_H_
