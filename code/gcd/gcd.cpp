#include <iostream>
#include <vector>

long long gcd(long long m, long long n){
    while(n!=0){
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main(){
    std::cout << gcd(6,8) << std::endl;
}