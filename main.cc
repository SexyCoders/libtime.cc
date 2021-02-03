#include <stdio.h>
#include <my_time.h>
#include <string>
#include <iostream>

int main()
        {
                printf("Hello!\n");
                Time time;
                time.getTime();
                std::string print_time=time.toString();
                std::cout<<print_time<<"\n";
        }
