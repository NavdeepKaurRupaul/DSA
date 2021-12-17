#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int indexOfNRecursive(Node *head, int n) {
   if(head == NULL){
   	return -1;
   }
   int count =0;
   if(head->data==n){
   	return count;
   }
   int ans =indexOfNRecursive(head->next, n);
   if(ans==-1){
       return ans;
   }    
       else{
           return ans+1;
       }
 
}
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);
    
}


