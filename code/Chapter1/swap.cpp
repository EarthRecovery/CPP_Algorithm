#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> x {"aaa","bbb"};
    std::vector<std::string> y {"aaa=","bbb="};

    swap(x,y);

    for(auto q : x){
        std::cout << q << std::endl;
    }
}

void swap( std::vector<std::string> &x, std::vector<std::string> &y){
    std::vector<std::string> temp = std::move(x);
    x = std::move(y);
    y = std::move(temp);
}
