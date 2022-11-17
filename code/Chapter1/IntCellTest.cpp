#include <iostream>
#include "IntCell.h"

int main(){
    IntCell intCell(23);
    intCell.write(24);
    int a = intCell.read();
    std::cout << a << std::endl;
}