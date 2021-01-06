#include <my_time.h>


extern "C" 
    {
        PHPCPP_EXPORT void *get_module() 
            {
                static Php::Extension myExtensionTime("microsun_time", "0.1");
                Php::Class<Time> time("Time");
                time.method<&Time::getTimeString>("getTimeString",{});
                time.method<&Time::saveTime>("saveTime",{Php::ByVal("parameter",Php::Type::String,true)});
                time.method<&Time::phpget_second> ("get_second",{});
                time.method<&Time::phpget_minute> ("get_minute",{});
                time.method<&Time::phpget_hour> ("get_hour",{});
                time.method<&Time::phpget_weekday> ("get_weekday",{});
                time.method<&Time::phpget_day> ("get_day",{});
                time.method<&Time::phpget_month> ("get_month",{});
                time.method<&Time::phpget_year> ("get_year",{});
                myExtensionTime.add(std::move(time));
                return myExtensionTime;
            }
    }
