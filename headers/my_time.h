#include <string>
#include <vector>

#ifndef TIME_H
#define TIME_H

#define WEEKDAY_YES 1
#define WEEKDAY_NO 0

class Time
	{
		public:
			int second;
			int minute;
			int hour;
			int weekday;
			int day;
			int month;
			int year;

			std::vector<std::string> _week_days;
			std::vector<std::string> _months;
		public:
			Time()
				{
					this->_initialize();
				}

			//output functions
			std::string toString();
			//formated output
			std::string DatetoStringf(const char* format);
			std::string TimetoStringf(const char* format);
			std::string toStringf(const char* date_format,const char* time_format,int week_day_flag);
			//format has to be along the lines of dmyl; date month year long (or s->short) and the delimiter for date
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

			void _initialize()
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
	};

#endif
