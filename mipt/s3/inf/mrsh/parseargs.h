#ifndef PARSEARHS_H
#define PARSEARHS_H

// Parsing command line arguments

// parse string and store result to args, argsc
// example:
// string = "ls    -l -a /"
// => args={"ls", "-l", "-a", "/"}
// => argsc=4

//#define DEBUG

void parseArgs(char* string, int strLen, char** args, int* argsc);

//prints args
void printArgs(char** args, int argsc);

// malloc strlen * strlen to args
void mallocArgs(char*** args, int strLen);

//frees args
void freeArgs(char*** args, int* argsc, int strLen);

#endif
