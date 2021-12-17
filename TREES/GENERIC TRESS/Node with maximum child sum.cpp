#include <iostream>
using namespace std;
#include <vector>
#include <queue>
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
template <typename T>
class Pair{
    public:
    TreeNode<T>* x;
    int sum;
};
Pair<int>* maxNode(TreeNode<int>* root){
     Pair<int> *p=new Pair<int>();
    p->x=root;
    p->sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        p->sum=p->sum+root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++)
    {
        Pair<int> *temp=maxNode(root->children[i]);
        if(temp->sum>p->sum)
        {
            p=temp;
        }
    }
    return p;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    return maxNode(root)->x;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}



