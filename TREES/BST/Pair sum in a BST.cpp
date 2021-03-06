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
#include <stack>
int countNodes(BinaryTreeNode<int> *root) {
if(root == NULL) {
return 0;
}
return countNodes(root -> left) + countNodes(root -> right) + 1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
if(root == NULL) {
return;
}
int totalCount = countNodes(root);
int count = 0;
stack<BinaryTreeNode<int>*> inorder;
stack<BinaryTreeNode<int>*> revInorder;
BinaryTreeNode<int> *temp = root;
while(temp != NULL) {
inorder.push(temp);
temp = temp -> left;
}
temp = root;
while(temp != NULL) {
revInorder.push(temp);
temp = temp -> right;
}
while(count < totalCount - 1) {
BinaryTreeNode<int> *top1 = inorder.top();
BinaryTreeNode<int> *top2 = revInorder.top();
if(top1 -> data + top2 -> data == s) {
cout << top1 -> data << " " << top2 -> data << endl;
BinaryTreeNode<int> *top = top1;
inorder.pop();
count++;
if(top -> right != NULL) {
top = top -> right;
while(top != NULL) {
inorder.push(top);
top = top -> left;
}
}
top = top2;
revInorder.pop();
count++;
if(top -> left != NULL) {
top = top -> left;
while(top != NULL) {
revInorder.push(top);
top = top -> right;
}
}
}
else if(top1 -> data + top2 -> data > s) {
BinaryTreeNode<int> *top = top2;
revInorder.pop();
count++;
    if(top -> left != NULL) {
top = top -> left;
while(top != NULL) {
revInorder.push(top);
top = top -> right;
}
}
}
else {
BinaryTreeNode<int> *top = top1;
inorder.pop();
count++;
if(top -> right != NULL) {
top = top -> right;
while(top != NULL) {
inorder.push(top);
top = top -> left;
}
}
}
}
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}

