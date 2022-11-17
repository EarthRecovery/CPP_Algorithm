#ifndef INTCELL_H
#define INTCELL_H

class IntCell{
    public:
        explicit IntCell(int initialValue = 0);
        int read() const;
        void write( int x );
    private:
        int storedValue;
};

#endif