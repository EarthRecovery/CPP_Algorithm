#include <iostream>
#include "SearchTreeCSDN.cpp"

using namespace std;

int main(){
    BinarySearchTree<int> binarySearchTree = new BinarySearchTree<int>();
    for(int i=0;i<10;i++){
        binarySearchTree.insert(i);
    }
    std::cout << binarySearchTree.findMax() << std::endl;
}