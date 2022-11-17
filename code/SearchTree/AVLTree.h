#ifndef AVL_TREE
#define AVL_TREE
 
#include<iomanip>
#include<iostream>
#include <cstring>
#include <memory>
using namespace std;
 
template<class T>
class AVLTreeNode
{
    public:
        T key;    // 关键字（键值）
        int height;    // 高度
        AVLTreeNode *left;    // 左孩子
        AVLTreeNode *right;    // 右孩子
    
        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r) :
            key(value) ,left(l),right(r) {}
};
 
template<class T>
class AVLTree
{
    private:
        AVLTreeNode<T> *root;    // 根结点
    
    public:
        // 外部接口 
         AVLTree();
         ~AVLTree();
         
        // 获取树的高度
        int height();
        // 比较两个值的大小 
        int max(int a, int b);
        
        // 前序遍历
        void preOrder();
        // 中序遍历
        void inOrder();
        // 后序遍历
        void postOrder();
        
        // （递归实现）查找AVL树中键值为key的结点
        AVLTreeNode<T>* search(T key);
        // （非递归实现）查找AVL树中键值为key的结点
        AVLTreeNode<T>* iterativeSearch(T key);
        
        // 查找最小结点：返回最小结点的键值
        T minimum();
        // 查找最大结点：返回最大结点的键值
        T maximum();
        
        // 将结点插入到AVL树中
        void insert(T key);
        // 删除结点
        void remove(T key);
        
        // 销毁AVL树
        void destroy();
        
        // 打印AVL树
        void print();
    
    private:
        // 内部接口 
        // 获取树的高度
        int height(AVLTreeNode<T> *tree);
        
        // 前序遍历
        void preOrder(AVLTreeNode<T> *tree) const;
        // 中序遍历
        void inOrder(AVLTreeNode<T> *tree) const;
        // 后序遍历
        void postOrder(AVLTreeNode<T> *tree) const;
        
        // （递归实现）查找AVL树中键值为key的结点
        AVLTreeNode<T>* search(AVLTreeNode<T> *x, T key) const;
        // （非递归实现）查找AVL树中键值为key的结点
        AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T> *x, T key) const;
        
        // 返回最小结点 
        AVLTreeNode<T>* minimum(AVLTreeNode<T> *tree);
        // 返回最大结点 
        AVLTreeNode<T>* maximum(AVLTreeNode<T> *tree);
        
        // 将结点插入到AVL树中
        AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
        // 删除结点，并返回被删除的结点 
        AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T> *z);
        
        // 销毁AVL树
        void destroy(AVLTreeNode<T>* &tree);
        
        // 打印AVL树
        void print(AVLTreeNode<T> *tree,T key,int direction);
        
        // LL：左左对应的情况(左单旋转)
        AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T> *k2);
        // RR：右右对应的情况(右单旋转)
        AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T> *k1);
        // LR：左右对应的情况(左双旋转)
        AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T> *k3);
        // RL：右左对应的情况(右双旋转)
        AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T> *k1);    
};
 
template<class T>
AVLTree<T>::AVLTree(): root(NULL)
{
}
 
template<class T>
AVLTree<T>::~AVLTree()
{
    destroy(root);
}
 
template<class T>
int AVLTree<T>::height(AVLTreeNode<T> *tree)
{
    if(tree!=NULL)
        return tree->height;
    return 0;
}
 
template<class T>
int AVLTree<T>::height()
{
    return height(root);
}
 
template<class T>
int AVLTree<T>::max(int a, int b)
{
    return a>b ? a : b;
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T> *k2)
{
    AVLTreeNode<T> *k1;
    
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    
    return k1;
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T> *k1)
{
    AVLTreeNode<T> *k2;
    
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(k1->height, height(k2->right)) + 1;
    
    return k2; 
}
 
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
    k3->left = rightRightRotation(k3->left);
    
    return leftLeftRotation(k3);
}
 
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);
    
    return rightRightRotation(k1);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{

    // if(tree==NULL)
    // {
    //     // 新建结点 
    //     tree = new AVLTreeNode<T>(key, NULL, NULL);
    //     if(tree==NULL)
    //     {
    //         cout<<"ERROR: create avltree node failed!"<<endl;
    //         return NULL;
    //     }
    // }
    // else if(key<tree->key)
    // {
    //     tree->left = insert(tree->left, key);
    //     // 插入结点后，若AVL树失去平衡，则进行相应的调节
    //     if(height(tree->left)-height(tree->right)==2)
    //     {
    //         if(key<tree->left->key)
    //             tree = leftLeftRotation(tree);
    //         else
    //             tree = leftRightRotation(tree);
    //     } 
    // }
    // else
    // {
    //     tree->right = insert(tree->right, key);
    //     // 插入结点后，若AVL树失去平衡，则进行相应的调节
    //     if(height(tree->right)-height(tree->left)==2)
    //     {
    //         if(key>tree->right->key)
    //             tree = rightRightRotation(tree);
    //         else
    //             tree = rightLeftRotation(tree);
    //     } 
    // }
    
    // tree->height = max(height(tree->left), height(tree->right)) + 1;
    
    // return tree;

    if(tree == NULL){
        tree = new AVLTreeNode<T>(key, NULL, NULL);
    }else if(key < tree->key){
        tree->left = insert(tree->left,key);
        if((height(tree->left) - height(tree->right)) == 2){
            if(key < tree->left->key) tree = leftLeftRotation(tree);
            else tree = leftRightRotation(tree);
        }
    }else{
        tree->right = insert(tree->right,key);
        if((height(tree->right) - height(tree->left)) == 2){
            if(key > tree->right->key) tree = rightRightRotation(tree);
            else tree = rightLeftRotation(tree);
        }
        
    }

    tree->height = max(height(tree->left),height(tree->right))+1;
    return tree;
}
 
template<class T>
void AVLTree<T>::insert(T key)
{
    insert(root,key);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T> *z)
{
    // 根为空 或者 没有要删除的结点
    if(tree==NULL || z==NULL)
        return NULL;
    if(z->key<tree->key)
    {
        tree->left = remove(tree->left, z);
        // 删除结点后，若AVL树失去平衡，则进行相应调节
        if(height(tree->right)-height(tree->left)==2)
        {
            AVLTreeNode<T> *r = tree->right;
            if(height(r->left)>height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        } 
    } 
    else if(z->key>tree->key)
    {
        tree->right = remove(tree->right, z);
        if(height(tree->left)-height(tree->right)==2)
        {
            AVLTreeNode<T> *r = tree->left;
            if(height(r->left)<height(r->right))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else    // tree是对应要删除的结点 
    {
        // tree的左右孩子都非空 
        if((tree->left!=NULL)&&(tree->right!=NULL))
        {
            if(height(tree->left)>height(tree->right))
            {
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T> *max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            }
            else
            {
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T> *min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min); 
            }
        }
        else
        {
            AVLTreeNode<T> *tmp = tree;
            tree = (tree->left!=NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }
    
    return tree;
}
 
template<class T>
void AVLTree<T>::remove(T key)
{
    AVLTreeNode<T> *z;
    if((z=search(root,key))!=NULL)
        root = remove(root,z);
}
 
template<class T>
void AVLTree<T>::preOrder(AVLTreeNode<T> *tree) const
{
    if(tree!=NULL){
        cout << tree->key << " " << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
 
template<class T>
void AVLTree<T>::preOrder()
{
    preOrder(root);
}
 
template<class T>
void AVLTree<T>::inOrder(AVLTreeNode<T> *tree) const{
    if(tree != NULL){
        inOrder(tree->left);
        cout<< tree->key << " " << endl;
        inOrder(tree->right);
    }
}
 
template<class T>
void AVLTree<T>::inOrder()
{
    inOrder(root);
}
 
template<class T>
void AVLTree<T>::postOrder(AVLTreeNode<T> *tree) const
{
    if(tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " " << endl;
    }
}
 
template<class T>
void AVLTree<T>::postOrder()
{
    postOrder(root);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T> *x, T key) const
{
    if(x==NULL || x->key==key)
        return x;
    if(key<x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
    return search(root, key);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T> *x, T key) const
{
    while(x!=NULL && x->key!=key)
    {
        if(key<x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(T key)
{
    return iterativeSearch(root, key);
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T> *tree)
{
    if(tree==NULL)
        return NULL;
    while(tree->left!=NULL)
        tree = tree->left;
    return tree;
}
 
template<class T>
T AVLTree<T>::minimum()
{
    AVLTreeNode<T> *p = minimum(root);
    if(p!=NULL)
        return p->key;
    return (T)NULL;
}
 
template<class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T> *tree)
{
    if(tree==NULL)
        return NULL;
    while(tree->right!=NULL)
        tree = tree->right;
    return tree;
}
 
template<class T>
T AVLTree<T>::maximum()
{
    AVLTreeNode<T> *p = maximum(root);
    if(p!=NULL)
        return p->key;
    return (T)NULL;
}
 
template<class T>
void AVLTree<T>::destroy(AVLTreeNode<T> *&tree)
{
    if(tree==NULL)
        return ;
    if(tree->left!=NULL)
        destroy(tree->left);
    if(tree->right!=NULL)
        destroy(tree->right);
    delete tree;
}
 
template<class T>
void AVLTree<T>::destroy()
{
    destroy(root);
}
 
template<class T>
void AVLTree<T>::print(AVLTreeNode<T> *tree, T key, int direction)
{
    if(tree!=NULL)
    {
        if(direction==0)
            cout<<setw(2)<<tree->key<<"is root"<<endl;
        else
            cout<<setw(2)<<tree->key<<"is"<<setw(2)<<key<<"'s"<<setw(12)<<(direction==1 ? "right child" : "left child")<<endl;
        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}
 
template<class T>
void AVLTree<T>::print()
{
    if(root!=NULL)
        print(root, root->key, 0);
}
 
#endif
 
// if(tree==NULL)
    // {
    //     // 新建结点 
    //     tree = new AVLTreeNode<T>(key, NULL, NULL);
    //     if(tree==NULL)
    //     {
    //         cout<<"ERROR: create avltree node failed!"<<endl;
    //         return NULL;
    //     }
    // }
    // else if(key<tree->key)
    // {
    //     tree->left = insert(tree->left, key);
    //     // 插入结点后，若AVL树失去平衡，则进行相应的调节
    //     if(height(tree->left)-height(tree->right)==2)
    //     {
    //         if(key<tree->left->key)
    //             tree = leftLeftRotation(tree);
    //         else
    //             tree = leftRightRotation(tree);
    //     } 
    // }
    // else
    // {
    //     tree->right = insert(tree->right, key);
    //     // 插入结点后，若AVL树失去平衡，则进行相应的调节
    //     if(height(tree->right)-height(tree->left)==2)
    //     {
    //         if(key>tree->right->key)
    //             tree = rightRightRotation(tree);
    //         else
    //             tree = rightLeftRotation(tree);
    //     } 
    // }
    
    // tree->height = max(height(tree->left), height(tree->right)) + 1;
    
    // return tree;

