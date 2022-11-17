#include <iostream>
#include <vector>

template<typename Comparable>
Comparable binarySearch(const std::vector<Comparable> &a, const Comparable &target){
    int low = 0, high = a.size()-1;
    while(low <= high){
        int mid = (high-low)/2;
        if(a[mid] == target) return mid;
        if(a[mid] > target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
}

int main(){
    std::vector<int> a{2,3,4,5};
    std::cout << binarySearch(a,3) << std::endl;
}