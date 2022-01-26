# CWE-476
This code is vulnerable to the [CWE-476 "NULL Pointer Dereference"](http://cwe.mitre.org/data/definitions/476.html) weakness, you can experiment with it yourself.

## Dependencies
To build this application you need:
- SFML >= 2.5.1 library

## Run example
To run this application:
1) `sudo apt-get install libsfml-dev`
2) `mkdir build`
3) `cd build`
4) `cmake ..`
5) `make -j`
6) `make install`
7) `./stratego`

Once you deploy your units on the board (it is possible to use RANDOM button in order to make it faster) try to click any unit in the first row. It will result in `Segmentation Fault` error due to the null pointer dereference.

## Reference
Link to the original application: https://github.com/WojtekMs/stratego
