#include <iostream>
using namespace std;
#include <queue>

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

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
BinaryTreeNode<int>* constructTreeFromArray(int *input, int startindex, int endindex){
	if(startindex > endindex){
		return NULL;
	}
	int rootindex = (startindex + endindex)/2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int> (input[rootindex]);
	BinaryTreeNode<int>* leftroot = constructTreeFromArray(input,startindex,rootindex-1);
	BinaryTreeNode<int>* rightroot = constructTreeFromArray(input, rootindex + 1, endindex);
	root->left = leftroot;
	root->right = rightroot;
	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	int startindex = 0;
	int endindex = n-1;
	return constructTreeFromArray(input, startindex, endindex);
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
}

