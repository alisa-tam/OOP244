// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iomanip>
#include "Date.h"

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  void Date::errCode(int errorCode)
  {
	  error = errorCode;
  }

  Date::Date()
  {
	  year = 0;
	  month = 0;
	  day = 0;
	  comparator = 0;
	  error = NO_ERROR;
  }

  Date::Date(int y, int m, int d) : Date()
  {
	  

	  if (y < min_year || y > max_year) {
		  error = YEAR_ERROR;
		  return;
	  }

	  if (m < 1 || m > 12) {
		  error = MON_ERROR;
		  return;
	  }
	  
	  if (d < 1 || d > mdays(m, y)) {
		  error = DAY_ERROR;
		  return;
	  }
	  
	  year = y;
	  month = m;
	  day = d;
	  comparator = year * 372 + month * 13 + day;
  }

  bool Date::operator==(const Date & rhs) const
  {
	  if (!bad() && !rhs.bad() && comparator && rhs.comparator) {
	
		 return comparator == rhs.comparator;
	  }
	  

	  return false;
  }

  bool Date::operator!=(const Date & rhs) const
  {
	  return !operator==(rhs);
	  
  }

  bool Date::operator<(const Date & rhs) const
  {
	  if (!bad() && !rhs.bad() && comparator && rhs.comparator) {

		  return comparator < rhs.comparator;
	  }
	  return false;
  }

  bool Date::operator>(const Date & rhs) const
  {
	  
	  if (!bad() && !rhs.bad() && comparator && rhs.comparator) {

		  return comparator > rhs.comparator;
	  }
	  return false;
  }

  bool Date::operator<=(const Date & rhs) const
  {
	  return !operator>(rhs);
  }

  bool Date::operator>=(const Date & rhs) const
  {
	  return !operator<(rhs);
  }

  int Date::errCode() const
  {
	  return error;
  }



  bool Date::bad() const
  {
	  return error != NO_ERROR;
  }

  std::istream & Date::read(std::istream & istr)
  {
	  int yr, mn, dy;
	  char slash;

	  istr >> yr >> slash >> mn >> slash >> dy;

	  if (istr.fail()) {
		  error = CIN_FAILED;
		  return istr;
	  }

	  Date date(yr, mn, dy);
	  error = date.error;
	  if (!date.bad()) {
		  *this = date;
	  } 
	  
	  return istr;
  }

  std::ostream & Date::write(std::ostream & ostr) const
  {
	  char tmp = ostr.fill();
	  ostr <<std::right<< year << "/" << std::setfill('0')<< std::setw(2)<< month << "/" << std::setfill('0') << std::setw(2) << day;
	  ostr << std::setfill(tmp);
	  return ostr;
  }

  std::ostream & operator<<(std::ostream & os, const Date & date)
  {
	  date.write(os);
	  return os;
  }

  std::istream & operator>>(std::istream & is, Date & date)
  {
	  date.read(is);
	  return is;
  }

}
