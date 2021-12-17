#include <iostream>
using namespace std;
#include <queue>
#include <stack>

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
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root==NULL){
    	return ;
	}
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            BinaryTreeNode<int>* top1=s1.top();
            s1.pop();
            cout<<top1->data<<" ";
            if(top1->left!=NULL){
                s2.push(top1->left);
            }
            if(top1->right!=NULL){
                s2.push(top1->right);
            }   
        }
        cout<<endl;
        while(!s2.empty()){
            BinaryTreeNode<int>* top2=s2.top();
            s2.pop();
            cout<<top2->data<<" ";
            if(top2->right!=NULL) {
                s1.push(top2->right);
            }
            if(top2->left!=NULL){
                s1.push(top2->left);
            }
        }
        cout<<endl;  
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}

