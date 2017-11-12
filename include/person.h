// person.h
#ifndef PERSON_H
#define PERSON_H
#include "main.h"
using namespace std;
/*
* Person是储存每个具体人信息的类
* 对错误或未定义的Person，name属性为空字符串
*/
struct Person{
  // a person's birthday and gender cannot be changed
  // Person()=delete;
  // Person(string name, Date birthday, Gender gender) : name(name), birthday(birthday), gender(gender) {}
  // Person
  
  /*
  * 对错误或未定义的Date，所有时间都定为0
  */
  // 1(id)+8(attr)=9(cols in csv)
  const string name;
  const string gender;

  const date_t birth_year;
  const date_t birth_month;
  const date_t birth_day;

  const date_t death_year;
  const date_t death_month;
  const date_t death_day;
};
#endif