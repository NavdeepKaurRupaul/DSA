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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(root==NULL)
        return NULL;
   TreeNode<int> *a=NULL;
    if(root->data>n){
        a=root;
    }
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*temp=nextLargerElement(root->children[i],n);
            if(a==NULL && temp!=NULL)
            {
                a=temp;
            }
        else if(temp!=NULL && temp->data<a->data)
        {
             a=temp;
        }
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}

