#include <iostream>
#include <vector>
#include <random>
using namespace std;

int maxSubRec(const vector<int> &a, int left, int right){
    //基准情况
    if(left == right){
        if(a[left] > 0){
            return a[left];
        }else{
            return 0;
        }
    }

    int center = (left+right)/2;
    int maxLeftSum = maxSubRec(a,0,center);
    int maxRightSum = maxSubRec(a,center+1,right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i=center;i>=left;i--){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int i=center;i<=right;i++){
        rightBorderSum += a[i];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }

    return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSuml(const vector<int> & a ){
    return maxSubRec(a,0,a.size()-1);
}

int main(){
    vector<int> a {2,3,-1,4,7,-8};
    cout << maxSubSuml(a) << endl;
}