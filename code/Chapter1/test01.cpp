#include <iostream>
using namespace std;

class A {
    public:
        A(){a = 0;}
        explicit A(int a){a = a;}
        int read() const 
        { return a; }
        void write(int a)
        { this->a = a; }
    private:
        int a;
};

int main(){
    A a(37);
    a.write(36);
    cout << a.read() << endl;
}