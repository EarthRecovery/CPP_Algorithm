#include "IntCell.h"

IntCell::IntCell( int initialValue ) : storedValue{ initialValue }
{
}

int IntCell::read() const 
{
    return storedValue;
}

void IntCell::write(int a)
{
    storedValue = a;
}