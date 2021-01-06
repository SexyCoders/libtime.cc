#include <string>
#include <vector>
#include <phpcpp.h>

#ifndef TIME_H
#define TIME_H

class Time : public Php::Base
	{
		public:
			int second;
			int minute;
			int hour;
			int weekday;
			int day;
			int month;
			int year;
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
				{
				return this->year;
				}
	};

#endif
