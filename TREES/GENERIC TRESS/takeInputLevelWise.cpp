#include<iostream>
using namespace std;
#include<vector>
#include<queue>
template <typename T>
 class TreeNode{
 	public:
 		T data;
 		vector<TreeNode<T>*> children;
 		TreeNode(T data){
 			this->data=data;
		 }
 };
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);	
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		TreeNode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"ENTER NUMBER OF CHILDREN OF "<<front->data <<endl;
		int NumChild;
		cin>>NumChild;
		for(int i=0;i<NumChild;i++){
			int ChildData;
			cout<<"ENTER "<<i<<" "<<"CHILD OF "<<front->data<<endl;
			cin>>ChildData;
			TreeNode<int>* child = new TreeNode<int>(ChildData);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

 int main(){
 	TreeNode <int> * root=takeInputLevelWise();
 	printTree(root);
 }
