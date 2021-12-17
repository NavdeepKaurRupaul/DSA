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
int length(Node *head) {
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
    	count++;
    	temp=temp->next;
	}
	return count;
}

Node* insertnode(Node*head, int i, int data){
	Node* newnode=new Node(data);
	Node*temp=head;
	int count=0;
	if(i==0){
		newnode->next=head;
		head=newnode;
		return head;
	}
	while(temp!= NULL && count<i-1){
		temp=temp->next;
		count++;
	}
	if(temp!= NULL){
		Node*a=temp->next;
		temp->next=newnode;
		newnode->next=a;
		/* OR
		newnode->next=temp->next;
		temp->next=newnode;
		*/
	}
	return head;
}
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
    print(head);
    int i,data;
    cin>>i>>data;
    insertnode(head,i,data);
    print(head);
}



