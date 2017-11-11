// person.h
#include <string>
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
    struct Date {
        // aggregate class(struct), all public
      Date(int year, int month, int day) : year(year), month(month), day(day) {
          if (!isValid()) {
              year = month = day = 0;
          }
      };
      int year;
      int month;
      int day;
      bool isValid() const;
    };
    // a person's birthday and gender cannot be changed
    Person()=delete;
    Person(string name, Date birthday, Gender gender) : name(name), birthday(birthday), gender(gender) {}
    string getName() const;
    bool setName();
private:
    string name;
public:
    const Date birthday;
    const Gender gender;
};