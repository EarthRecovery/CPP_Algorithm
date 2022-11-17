#include <vector>
#include <stack>
#include <iostream>

struct TreeNode{
    char element;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode() : element(0),leftChild(nullptr),rightChild(nullptr){};
    TreeNode(char a) : element(a),leftChild(nullptr),rightChild(nullptr){};
    TreeNode(char a,TreeNode* b,TreeNode* c) : element(a),leftChild(b),rightChild(c){};
    TreeNode(TreeNode *a) : element(a->element),leftChild(a->leftChild),rightChild(a->rightChild){};
};

bool isNumber(const char &a){
    if(a != '+' && a != '-' && a != '*' && a != '/') return true;
    return false;
}

TreeNode* getTree(const std::vector<char> &list){
    std::stack<TreeNode*> Nodestack;
    for(char c : list){
        if(isNumber(c)){
            Nodestack.push(new TreeNode(c));
        }else{
            TreeNode* temp1 = Nodestack.top();
            Nodestack.pop();
            TreeNode* temp2 = Nodestack.top();
            Nodestack.pop();
            Nodestack.push(new TreeNode(c,temp1,temp2));

        }
    }
    TreeNode* ans = new TreeNode(Nodestack.top());
    return ans;
}

void selectAll(TreeNode* &a){
    std::cout << a->element << " ";
    if(a->leftChild!=nullptr && a->rightChild != nullptr){
        selectAll(a->leftChild);
        selectAll(a->rightChild);
    }
    if(a->leftChild!=nullptr && a->rightChild == nullptr){
        selectAll(a->leftChild);
    }
    if(a->leftChild==nullptr && a->rightChild != nullptr){
        selectAll(a->rightChild);
    }
}

int main(){
    std::vector<char> a{'a','b','+','c','d','e','+','*','*'};
    TreeNode* ans;
    ans = getTree(a);
    selectAll(ans);
}