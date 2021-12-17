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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
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
#include<climits>
class quad{
    public:
  int minimum;
    int maximum;
    bool isBST;
    int height;
};
quad largesthelp(BinaryTreeNode<int> *root,int maximum,int minimum,int heightBST){
    if(root==NULL){
    quad a;
        a.minimum=INT_MAX;
        a.maximum=INT_MIN;
        a.isBST=true;
        a.height=0;
        
        return a;
    }
    quad a=largesthelp(root->left,maximum,minimum,heightBST);
    quad b=largesthelp(root->right,maximum,minimum,heightBST);
    if(root->data>a.maximum&&root->data<=b.minimum&&a.isBST&&b.isBST){
        quad c;
       c.minimum=min(root->data,min(a.minimum,b.minimum));
        c.maximum=max(root->data,max(a.maximum,b.maximum));
        c.isBST=true;
        c.height=1+max(a.height,b.height);
        
        return c;
        
    }
    else{
        
        quad c;
        c.minimum=min(root->data,min(a.minimum,b.minimum));
        c.maximum=max(root->data,max(a.maximum,b.maximum));
        c.isBST=false;
        c.height=max(a.height,b.height);
        
        return c;    
    }   
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largesthelp(root,INT_MAX,INT_MIN,0).height;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}

