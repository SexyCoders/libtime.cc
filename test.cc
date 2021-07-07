#include "./headers/my_time.h"
#include <string>
#include <iostream>

int main()
	{
		Time T;
		T.getTime();
		std::string test=T.toStringf("myl","c",WEEKDAY_YES);
		std::cout<<test;
	}
