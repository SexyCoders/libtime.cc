#include <my_time.h>
#include <iostream>

int Time::_check_before_minutes(int MIN)
        {
                Time tmp;
                tmp.getTime();
                unsigned long int tmp_min=tmp.min();
                unsigned long int this_min=this->min();
                if(this_min+MIN>=tmp_min)
                        return 1;
                else
                        return 0;
        }

int Time::_check_after_minutes(int MIN)
        {
                Time tmp;
                tmp.getTime();
                unsigned long int tmp_min=tmp.min();
                unsigned long int this_min=this->min();
                if(this_min+MIN>=tmp_min)
                        return 0;
                else
                        return 1;
        }
