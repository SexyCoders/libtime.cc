#include <string>
#include <vector>
<<<<<<< HEAD
=======
#include <phpcpp.h>
>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce

#ifndef TIME_H
#define TIME_H

<<<<<<< HEAD
class Time
=======
class Time : public Php::Base
>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce
	{
		public:
			int second;
			int minute;
			int hour;
			int weekday;
			int day;
			int month;
			int year;
<<<<<<< HEAD

			std::vector<std::string> _week_days;
			std::vector<std::string> _months;
		public:
			Time()
				{
					this->_week_days.push_back("Monday");
					this->_week_days.push_back("Tuesday");
					this->_week_days.push_back("Wednessday");
					this->_week_days.push_back("Thursday");
					this->_week_days.push_back("Friday");
					this->_week_days.push_back("Saturday");
					this->_week_days.push_back("Sunday");

					this->_months.push_back("January");
					this->_months.push_back("February");
					this->_months.push_back("March");
					this->_months.push_back("April");
					this->_months.push_back("May");
					this->_months.push_back("June");
					this->_months.push_back("July");
					this->_months.push_back("August");
					this->_months.push_back("September");
					this->_months.push_back("October");
					this->_months.push_back("November");
					this->_months.push_back("December");
				}

			//output functions
			std::string toString();
			//std::string toString(std::string);

			//conversion functions
			unsigned long int min();
			unsigned long int _to_min();
			
			//input functions
			void fromString(std::string);
			Time getTime();

			//operators
			Time operator=(Time src);
			int operator==(Time);
			int operator<(int);
			int operator>(int);
			int operator<(Time);
			int operator>(Time);

			//operator functions
			int _check_before_minutes(int);
			int _check_after_minutes(int);

			//getters and setters
			int get_second(void)
				{
				return this->second;
				}
			int get_minute(void)
				{
				return this->minute;
				}
			int get_hour(void)
				{
				return this->hour;
				}
			int get_weekday(void)
				{
				return this->weekday;
				}
			int get_day(void)
				{
				return this->day;
				}
			int get_month(void)
				{
				return this->month;
				}
			int get_year(void)
=======
			std::vector<std::string> WeekDays;
			std::vector<std::string> Months;
		public:
			Time();
			int operator==(Time);
			int CheckBeforeMinutes(int);
			std::string toString();
			std::string toString(std::string);
			void fromString(std::string);
			Time getTime();
			Php::Value getTimeString()
				{
					this->getTime();
					std::string to_return=toString();
				return to_return;
				}
			Php::Value saveTime(Php::Parameters &);
			Time operator=(Time src)
				{
					this->second=src.second;
					this->minute=src.minute;
					this->hour=src.hour;
					this->weekday=src.weekday;
					this->day=src.day;
					this->month=src.month;
					this->year=src.year;
				return *this;
				}
			inline int get_second(void)
				{
				return this->second;
				}
			inline int get_minute(void)
				{
				return this->minute;
				}
			inline int get_hour(void)
				{
				return this->hour;
				}
			inline int get_weekday(void)
				{
				return this->weekday;
				}
			inline int get_day(void)
				{
				return this->day;
				}
			inline int get_month(void)
				{
				return this->month;
				}
			inline int get_year(void)
>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce
				{
				return this->year;
				}
	};

#endif
