// person.h
#include <string>
#include "main.h"
using namespace std;
/*
* Person是储存每个具体人信息的类
* 对错误或未定义的Person，name属性为空字符串
*/
struct Person {
public:
  // a person's birthday and gender cannot be changed
  // Person()=delete;
  // Person(string name, Date birthday, Gender gender) : name(name), birthday(birthday), gender(gender) {}
  // Person
public:
  /*
  * 对错误或未定义的Date，所有时间都定为0
  */
  const string name;
  const Gender gender;
  const id_type mother;
  // const Date birthday;
  // const Date deathday;
};