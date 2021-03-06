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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorderHelper(int *postorder, int *inorder, int Spost, int Epost, int Sin, int Ein){
	int rootData = postorder[Epost];
	int rootindex = -1;
    if(Spost > Epost){
        return NULL;
    }
	for(int i = Sin; i <= Ein; i++){
		if(inorder[i] == rootData){
			rootindex = i;
			break;
		}
	}
	int LinS = Sin;
	int LinE = rootindex-1;
	int LpostS = Spost;
	int LpostE = LinE - LinS + LpostS;
	
	int RinS = rootindex+1;
	int RinE = Ein;
	int RpostS = LpostE + 1;
	int RpostE = RinE - RinS + RpostS;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = getTreeFromPostorderAndInorderHelper(postorder, inorder, LpostS, LpostE, LinS, LinE);
	root->right = getTreeFromPostorderAndInorderHelper(postorder, inorder, RpostS, RpostE, RinS, RinE);
	return root;
	
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
	return getTreeFromPostorderAndInorderHelper(postorder, inorder, 0, postLength-1, 0, inLength-1);
}
int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>post[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}

