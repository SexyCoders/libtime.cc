#include <my_time.h>
#include <iostream>

Time Time::operator=(Time src)
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

int Time::operator==(Time comp)
        {
                if(this->weekday!=comp.weekday)
                        return 0;
                else if(this->day!=comp.day)
                        return 0;
                else if(this->month!=comp.month)
                        return 0;
                else if(this->year!=comp.year)
                        return 0;
                else if(this->hour!=comp.hour)
                        return 0;
                else if(this->minute!=comp.minute)
                        return 0;
                else if(this->second!=comp.second)
                        return 0;
        return 1;
        }

int Time::operator<(int MIN)
        {
        return this->_check_before_minutes(MIN);
        }

int Time::operator>(int MIN)
        {
        return this->_check_before_minutes(MIN);
        }

int Time::operator<(Time comp)
        {
                unsigned long int tmp_min=this->min();
                unsigned long int comp_min=comp.min();
        return (tmp_min<comp_min);
        }

int Time::operator>(Time comp)
        {
                unsigned long int tmp_min=this->min();
                unsigned long int comp_min=comp.min();
        return (tmp_min>comp_min);
        }
