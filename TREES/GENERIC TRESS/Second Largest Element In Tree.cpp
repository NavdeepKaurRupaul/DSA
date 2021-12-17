#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>
template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;   
    TreeNode(T data) {
        this->data = data;
    }   
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);  
    queue<TreeNode<int>*> pendingNodes; 
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode <int>* newNode(int key){
	TreeNode<int>* temp ;
	temp->data = key;
	return temp;
}
void secondlargestutil(TreeNode<int>* root, TreeNode<int>** first,TreeNode<int>** second ){
	if(root==NULL){
		return;
	}
	if(!(*first)){
		*first = root;
	}
	else if(root->data > (*first)->data){
		*second = *first;
		*first = root;
	}
	else if (!(*second) || root->data > (*second)->data){
		*second = root;
	}
	int numChildren = root->children.size();
	for(int i=0;i<numChildren;i++){
		secondlargestutil(root->children[i],first,second);
	}
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    TreeNode<int>* second = NULL;
    TreeNode<int>* first = NULL;
    secondlargestutil(root, &first, &second);
    if(second == NULL){
    	return NULL;
	}
	if(first->data==second->data){
		return NULL;
	}
	return second;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

