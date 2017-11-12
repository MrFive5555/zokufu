#ifndef DATE_H
#define DATE_H
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
#endif