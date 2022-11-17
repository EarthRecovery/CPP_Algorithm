#include <iostream>

template <typename Object>
struct TreeNode{
    Object element;
    TreeNode* firstChild;
    TreeNode* nextSibling;
};

template <typename Object>
struct TreeNode{
    Object element;
    TreeNode* leftChild;
    TreeNode* rightChild;
};