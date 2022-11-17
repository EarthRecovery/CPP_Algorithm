#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>

std::vector<char> read(const std::string &a){ 
    std::vector<char> ret;
    for(char c : a){
        if(c != ' '){
            ret.push_back(c);
        }
    }
    return ret;
}

int cal(const std::vector<char> &a){
    std::stack<int> stack;
    int temp1, temp2 ,temp3;
    for(char c : a){
        if(c >= '0' && c <= '9'){
            stack.push(c - '0');
            continue;
        }
        if(stack.size()<2){
            return -1;
        }
        switch(c){
            case '+':
                temp1 = stack.top();
                stack.pop();
                temp2 = stack.top();
                stack.pop();
                temp3 = temp1 + temp2;
                stack.push(temp3);
                break;
            case '-':
                temp1 = stack.top();
                stack.pop();
                temp2 = stack.top();
                stack.pop();
                temp3 = temp1 - temp2;
                stack.push(temp3);
                break;
            case '*':
                temp1 = stack.top();
                stack.pop();
                temp2 = stack.top();
                stack.pop();
                temp3 = temp1 * temp2;
                stack.push(temp3);
                break;
            case '/':
                temp1 = stack.top();
                stack.pop();
                temp2 = stack.top();
                stack.pop();
                temp3 = temp1 / temp2;
                stack.push(temp3);
                break;
            default:
                return -1;
        }
        
    }
    if(stack.size() != 1){
        return -1;
    }
    return stack.top();
}

int main(){
    std::string origin = "6 5 2 3 + 8 * + 3 + *";
    std::vector<char> read_ori = read(origin);
    int ans = cal(read_ori);
    std::cout << ans << std::endl;
}