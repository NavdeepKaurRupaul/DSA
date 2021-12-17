#include <iostream>
using namespace std;
#include <queue>
#include<vector>

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
vector<int>* GetRootToNodePath(BinaryTreeNode<int>* root, int data){
	if(root == NULL){
		return NULL;
	}
	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	vector<int>* leftoutput = GetRootToNodePath(root->left, data);
	if(leftoutput != NULL){
		leftoutput->push_back(root->data);
		return leftoutput;
	}
	vector<int>* rightoutput = GetRootToNodePath(root->right, data);
	if(rightoutput != NULL){
		rightoutput->push_back(root->data);
		return rightoutput;
	}
	else{
		return NULL;
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n ;
    //cout<<"ENTER NUMBER"<<endl;
    cin>>n;
    vector<int>* output = GetRootToNodePath(root, n);
    for(int i=0;i<output->size();i++){
    	cout<<output->at(i)<<endl;
	}
	//cout<<endl;
}
