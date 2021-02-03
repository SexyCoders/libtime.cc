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
<<<<<<< HEAD:sources/time_functions.cc
//std::string Time::toString(std::string parameter)
        //{
                //if(!parameter.compare("human"))
                        //{
                                //std::string DATE;
                                //DATE=this->WeekDays[this->weekday];
                                //DATE+=" ";
                                //DATE+=this->day;
                                //DATE+=" ";
                                //DATE+=this->Months[this->month];
                                //DATE+=" ";
                                //DATE+=this->year;
                                //DATE+=" ";
                                //DATE+=std::to_string(this->hour)+":"+std::to_string(this->minute)+":"+std::to_string(this->second);
                                //return DATE;
                        //}
                //else
                        //return "NON VALID PARAMETER";
        //}
=======

std::string Time::toString(std::string parameter)
        {
                if(!parameter.compare("h"))
                        {
                                std::string DATE;
                                DATE=this->WeekDays[this->weekday];
                                DATE+=" ";
                                DATE+=this->day;
                                DATE+=" ";
                                DATE+=this->Months[this->month];
                                DATE+=" ";
                                DATE+=this->year;
                                DATE+=" ";
                                DATE+=std::to_string(this->hour)+":"+std::to_string(this->minute)+":"+std::to_string(this->second);
                                return DATE;
                        }
                else
                        return "NON VALID PARAMETER";
        }

>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce:time_functions.cc
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

<<<<<<< HEAD:sources/time_functions.cc
unsigned long int Time::_to_min()
        {
        return (((this->month-1)*43800)+((this->day-1)*1440)+(this->hour*60)+(this->minute));
        }

unsigned long int Time::min()
        {
        return this->_to_min();
        }
=======
>>>>>>> 420b5c6e5f545982ca0e21c8f7c42ddbe472e0ce:time_functions.cc
