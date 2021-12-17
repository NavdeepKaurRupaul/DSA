#include <iostream>
using namespace std;
#include <queue>
#include<algorithm>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
class Pair {
	public:
		bool isBalance;
		int height;
};
Pair IsBalancedHelper(BinaryTreeNode<int> *root){
	if(root == NULL){
		Pair a;
		a.isBalance = true;
		a.height = 0;
		return a;
	}
	Pair left = IsBalancedHelper(root -> left);
	Pair right = IsBalancedHelper(root -> right);
	bool leftbalance=left.isBalance;
    int leftheight=left.height;
    bool rightbalance=right.isBalance;
    int rightheight=right.height;
    if((leftbalance==false && rightbalance==true) || (leftbalance==true && rightbalance==false)){
        Pair p;
        p.isBalance=false;
        p.height=1+(max(leftheight,rightheight));
        return p;
    }
    if(leftbalance==true && rightbalance==true){
        
        Pair p2;
        if(abs(leftheight-rightheight)<=1){
                p2.isBalance=true;
                p2.height=1+(max(rightheight,leftheight));
                return p2;  
        }
    }
    if(leftbalance==false &&  rightbalance==false){
        Pair p3;
        p3.isBalance=false;
        return p3;
    }
}
bool isBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL){
		return true;
	}
	return IsBalancedHelper(root).isBalance;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}

