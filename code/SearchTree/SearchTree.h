#include <utility>
template <typename Comparable>
class BinarySearchTree{
    public:
        //四大函数
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &binarySearchTree): root(nullptr) {
            root = clone( binarySearchTree.root );
        }
        BinarySearchTree(BinarySearchTree && binarySearchTree): root(nullptr){
            root = clone( std::move(binarySearchTree));
        }
        ~BinarySearchTree(){
            makeEmpty();
        }
        
        bool Contains(const Comparable& comparable) const;
        bool isEmpty() const;
        void Printtree() const;

        
        void insert(const Comparable& comparable);
        void remove(const Comparable& comparable);

        BinarySearchTree& operator= (const Comparable& comparable);
        BinarySearchTree& operator= (Comparable&& comparable);

    private:
        //节点
        struct BinaryNode{
            Comparable element;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode(const Comparable &el, BinaryNode *l, BinaryNode *r) : element(el),left(l),right(r){}
            BinaryNode(Comparable && el, BinaryNode *l, BinaryNode *r) : element(std::move(el)),left(l),right(r){}
        };

        BinaryNode* root;

        bool contains(const Comparable &rhs, BinaryNode* node) const;
        void insert(const Comparable &rhs,BinaryNode* &node);
        void remove(const Comparable& comparable,BinaryNode* &node);

        BinaryNode* findMin(BinaryNode* t) const;
        BinaryNode* findMax(BinaryNode* t) const;

        BinaryNode* clone( BinaryNode* t) const{
            if(t == nullptr) return nullptr;
            else return new BinaryNode(t->element, clone(t->left),clone(t->right));
        }

        void makeEmpty(BinaryNode* &t){
            if(t != nullptr){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }

        const Comparable& findMin() const;
        const Comparable& findMax() const;
};

template <typename Comparable>
bool BinarySearchTree<Comparable>::Contains(const Comparable& comparable) const{
    return contains(comparable,root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& comparable){
    insert(comparable,root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& comparable){
    remove(comparable,root);
}

//是否包含？使用递归
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinaryNode* node) const{
    if(node == nullptr) return false;
    else if(x < node->element) return contains(x,node->left);
    else if(x > node->element) return contains(x,node->right);
    else return true;
}

//递归查找最小数
template <typename Comparable>
BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* t) const{
    if(t==nullptr) return nullptr;
    if(t->left == nullptr) return t;
    return findMin(t->left);
}

//循环查找最大数
template <typename Comparable>
BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* t) const{
    if(t!=nullptr){
        while(t->right != nullptr){
            t = t->right;
        }
    }
    return t;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &rhs,BinaryNode* &t){
    if(t == nullptr){
        t = new BinaryNode(rhs,nullptr,nullptr);
        return;
    }
    else if( rhs < t->element) insert(rhs,t->left);
    else if( rhs > t->element) insert(rhs,t->right);
    else
        return;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x,BinaryNode* &t){
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
};

