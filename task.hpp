#ifndef task_hpp
#define task_hpp

#include "iostream"
#include <stdlib.h>
using namespace std;

struct custom_array {
    int* ptr;
    int length;
};

custom_array findIndexs(char**& strings, int& array_length, int& str_length);
void deleteElemet(char**& strings, int& array_length, int index);

#endif /* task_hpp */
