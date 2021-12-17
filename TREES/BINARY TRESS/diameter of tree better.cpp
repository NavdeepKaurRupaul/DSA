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
pair<int, int> HeightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int, int> p;
		p.first = 0 ;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = HeightDiameter(root->left);
	pair<int, int> rightAns = HeightDiameter(root->right);
	int ld = leftAns.first;
	int lh = leftAns.second;
	int rd = rightAns.first;
	int rh = rightAns.second;
	
	int height = 1 + max(lh, rh);
	int diameter =  max(lh+rh, max(rd,ld));
	
	pair<int , int> p ;
	p.first = height;
	p.second = diameter;
	return p;
}
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL){
    	return ;
	}
	queue<BinaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size() != 0){
		BinaryTreeNode<int>* front = pendingnodes.front();
		cout<<front->data<<":";
        pendingnodes.pop();
        if(front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pendingnodes.push(front->left);
        }
        else{
            cout<<"L:"<<-1<<",";
        }
        if(front->right != NULL){
            cout<<"R:"<<front->right->data;
            pendingnodes.push(front->right);
        }
        else{
            cout<<"R:"<<-1;
        }
        cout<<endl;
	}
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    pair<int, int> p = HeightDiameter(root);
    cout<<"HEIGHT OF TREE IS : "<<p.first<<endl;
    cout<<"DIAMETER OF TREE IS : "<<p.second<<endl;
}

