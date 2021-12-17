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
void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==NULL){
    	return;
	}     
   queue<BinaryTreeNode<int>*>q;
   q.push(root);
   while(! q.empty()){
       BinaryTreeNode<int> * front =q.front();
       q.pop();
       if(front->left == NULL && front->right != NULL){
           cout<<front->right->data<<endl;
       }
       if(front->right == NULL && front->left != NULL){
           cout<<front->left->data<<endl;
       }   
       if(front->left != NULL){
           q.push(front->left);
       }
       if(front->right != NULL){
           q.push(front->right);
       }
   }  
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    nodesWithoutSibling(root);
}

