#include <cstring>
#include <my_time.h>
#include <sstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <iostream>

Time Time::getTime()
        {
                time_t now=time(0);
                struct tm time=*localtime(&now);
                this->second=time.tm_sec; 
                this->minute=time.tm_min;
                this->hour=time.tm_hour;
                this->weekday=time.tm_wday;
                this->day=time.tm_mday;
                this->month=time.tm_mon+1;
                this->year=time.tm_year+1900;
        return *this;
        }

std::string Time::toString()
        {
                std::string DATE;
                DATE+=std::to_string(this->weekday)+";";
                DATE+=std::to_string(this->day)+";";
                DATE+=std::to_string(this->month)+";";
                DATE+=std::to_string(this->year)+";";
                DATE+=std::to_string(this->hour)+";";
                DATE+=std::to_string(this->minute)+";";
                DATE+=std::to_string(this->second)+";";
        return DATE;
        }

void Time::fromString(std::string time_string)
        {
                this->weekday=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->day=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->month=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->year=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->hour=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->minute=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
                this->second=stoi(time_string.substr(0,time_string.find(";")));
                time_string.erase(0,time_string.find(";")+strlen(";"));
        }

unsigned long int Time::_to_min()
        {
        return (((this->month-1)*43800)+((this->day-1)*1440)+(this->hour*60)+(this->minute));
        }

unsigned long int Time::min()
        {
        return this->_to_min();
        }
