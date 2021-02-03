#include <my_time.h>
#include <iostream>

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

int Time::CheckBeforeMinutes(int MIN)
        {
                Time tmp;
                tmp.getTime();
                int tmp_min=(((tmp.month-1)*43800)+((tmp.day-1)*1440)+(tmp.hour*60)+(tmp.minute));
                int this_min=(((this->month-1)*43800)+((this->day-1)*1440)+(this->hour*60)+(this->minute));
                if(this_min+MIN>=tmp_min)
                        return 1;
                else
                        return 0;
        }
