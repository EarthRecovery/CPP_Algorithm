#include<iostream>
#include "AVLTree.h"
using namespace std;
 
static int arr[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
int main()
{
	int i,len;
	AVLTree<int> *tree = new AVLTree<int>();
	
	cout<<"add:";
	len = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<len;++i)
	{
		cout<<arr[i]<<" ";
		tree->insert(arr[i]);
	}

	tree->postOrder();
	cout<<"\npreOrder:";
	tree->preOrder();
	cout<<"\nmiddleOrder:";
	tree->inOrder();
	cout<<"\nostOrder:";
	tree->postOrder();
	
	// cout<<"\nheight: "<<tree->height()<<endl;
    // cout<<"min: "<<tree->minimum()<<endl;
    // cout<<"max: "<<tree->maximum()<<endl;
    // cout<<"detail: "<<endl;
    // tree->print();
    
    // i = 8;
    // cout<<"\ndelete root node:"<<i;
    // tree->remove(i);
    
    // cout<<"\nheight: "<<tree->height()<<endl;
    // cout<<"middleOrder:";
    // tree->inOrder();
    // cout<<"\ndetailed information: "<<endl;
    // tree->print();
    
    // 销毁二叉树
	tree->destroy();
	return 0; 
}