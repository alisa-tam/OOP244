/*Name: Alisa Tam
Student #: 131580177
Section: OOP244 AB
Email: aabramovici@gmail.com
*/
/////////////////////////////////////////////////////////////////

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;


  class Date {

	  int year;
	  int month;
	  int day;
	  int comparator;
	  int error;
      int mdays(int, int)const;
	  void errCode(int errorCode);
 
  public:
	  Date();
	  Date(int y, int m, int d);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
 
  };
  std::ostream & operator<<(std::ostream & os, const Date & date);
  std::istream & operator>>(std::istream & is, Date & date);





}
#endif