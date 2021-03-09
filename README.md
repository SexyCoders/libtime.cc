# Time.cc

Time.cc is a powerful time object library for C++.

## Why?
Time.cc was initially conceived for managing timestamps on web applications, like logs or registration dates.  

This library doesnt aim to replace the highly mature tm struct. Infact internally we use exactly that!  

## Our focus is <b>storing</b> a time for later use <b>not getting</b> the current time.   
# Features:
This library provides two sets of functions:  
The first set are simple wrapers over the almighty tm struct and simply provide an easier and simpler way to get the current time.  
The second set provides a huge collection of operators and string formaters!!  

This makes it able to:
- get current time using the tm struct
- load time from string (very usefull when working with databases/files)
- store time to string (for later loading)
- print time in any given format (returns string object in the requested format)
- compare time objects with each other (boolean comp for if statements or loops)

# Installation

To install please run the following inside the root directory of the downloaded source

```bash
make && make install
```

:information_source: Libraries will be installed under usr/local/lib and headers under usr/local/include.