#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
const Comparable findMax(const vector<Comparable> & a){
    Comparable maxIndex = 0;

    for(int i=0;i<a.size();i++){
        if(a[i] > maxIndex){
            maxIndex = a[i];
        }
    }

    return maxIndex;
}

int main(){
    vector<float> a = {3.0,4.0,5.0};

    cout << findMax(a) << endl;
}