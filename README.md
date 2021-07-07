# Time.cc

Time.cc is a powerful time object library for C++.

## Why?
Time.cc was initially conceived for managing timestamps on web applications, like logs or registration dates.  

This library doesnt aim to replace the highly mature tm struct. Infact internally we use exactly that!  

### Our focus is <b>storing</b> a time for later use <b>not getting</b> the current time.   
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

The <b>default brach</b> is the latest <b>stable</b> release version.  
If you wish to use the <b>development</b> version please change to the <b>master</b> branch.  

To install please run the following inside the root directory of the downloaded source

```bash
make && make install
```

:information_source: Libraries will be installed under usr/local/lib and headers under usr/local/include.

# Functions

The library provides three main function types:

## time functions
- getTime -> a very friendly wraper to the tm struct that get current time and stores it in the Time object
- fromString -> loads a Time object from a string (semicolon seperation OBLIGATORY see store())

## operators
Time.cc provides all mathematical operators and ports them to the Time object.  
You can compare add, substract etc between Time objects freely.  

## formated output functions
The "toStringf" function familly provides an easy way to create a string with your desired formatting for use in your application.

Please note that WE HAVE REMOVED DateToStringf and TimeToSringf. Use the generic toStringf for everything!

The generic "toStringf" prints anything in any format.  

the formatting is easy: 

### date format accepts following arguments
- d -> day
- m -> month
- y -> year
- l -> long
- s -> short
- delimiter

in the following order 

#### <b>[format][l/s][delimiter]</b> e.g. "mdyl/"  

:warning: format defaults to long and delimiter defaults to "-"
    
### time format argument
- "m" -> military time 
- "c" -> casual time

:information_source: the flags WEEKDAY_YES and WEEKDAY_NO are used to specify if you wish to have the weeday written in the output

For example 
```c
toStringf("mdyl/","m",WEEKDAY_YES);
```
 will create a string by printing:
- the weekday since we used flag weekday_yes
- the date in MONTH/DAY/YEAR format 
- the year will be written out since we specified long format ("l option")
- the time in military time (option "m")

# Contributing

This library is considered mature since all the possible features have been covered.  

## BUT

We will happily accept <b>maintenance</b> merges <b>AND new features</b> if they expand the functionality of the library.  

We are also looking for translations of the <b>documentation in other languages</b>!!  

Please contact us <a href="https://gitlab.com/dianshane">here</a>.
