# time.cc

A simple object oriented library to store time, get local time and export to various string formats.  

## Why
Since C already has a very powerful library for time the first question of yours propably was: Why do I need this?  
The answer is simple: Because this is a STORAGE library not a system time parser.  
This library provides structures and functions not only to get local time but to also store and retreive from memmory and storage.  

This library is not looking to replace the tm struct. Infact internally we are using exacrtly that to get local time.  
What we want is a reliable simple and portable way of storing time as an Object.  

## Further Documentation
- <a href="./doc/Properties.md">Properties</a>
