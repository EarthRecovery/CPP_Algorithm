#include <iostream>
#include <list>
using namespace std;

template<typename Container>
void removeEveryOtherItem(Container & lst){
    auto front = lst.begin();
    while(front != lst.end()){
        front = lst.erase(front);
        if(front != lst.end()) ++front;
    }
}

int main(){
    list<int> a{3,5,7,9,11,13};
    removeEveryOtherItem(a);
    
    for(int q : a){
        cout << q << " ";
    }
    cout << endl;

}