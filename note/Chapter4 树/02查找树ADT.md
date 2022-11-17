# 查找树ADT

二叉查找树的性质：对于每一个节点，左子树均小于X 的值，右子树均大于 X 的值

### 增加（insert）

```cpp
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &rhs,BinaryNode* &node){
    if(t == nullptr){
        node = new BinaryNode(rhs,nullptr,nullptr);
        return;
    }
    else if( rhs < node->element) insert(rhs,node->left);
    else if( rhs > node->element) insert(rhs,node->right);
    else
        return;
}
```

### 删除（remove）

```cpp
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& comparable,BinaryNode* &node){
    if(t == nullptr) return;
    if(x < t->element) remove(x, t->left);
    else if(x > t->element) remove(x, t->right);
    else if(t->left != nullptr && t->right != nullptr){ // 当被删除的左右子树都存在，将被删除的节点的值改为右子树最小值，
    //递归删除右子树最小值
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }else{ // 当只有一个子节点存在时
        BinaryNode* oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}
```

### 克隆（clone）

```cpp
BinaryNode *clone(BinaryNode * t) const{
            if(t == NULL)
                return NULL;
 
            return new BinaryNode(t->element, clone(t->left), clone(t->right), t->num);
        }
```

### 不平衡

当二叉查找树在经历大量insert/remove 后，由于remove 算法趋向于删除右子树，二叉查找树会变得不平衡

使用 AVL  树或者 自平衡伸缩树 可以解决这个问题
