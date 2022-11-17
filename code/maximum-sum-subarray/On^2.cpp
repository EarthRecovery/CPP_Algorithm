#include <iostream>
#include <vector>
#include <random>
using namespace std;

int maxSubSuml(const vector<int> & a ){
    int maxSum = 0;
    for(int i=0;i<a.size();i++){
        int sum = 0;
        for(int q=i;q<a.size();q++){
            sum += a[q];
            if(sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

int main(){
    vector<int> a {2,3,-1,4,7,-8};
    cout << maxSubSuml(a) << endl;
}