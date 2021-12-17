#include <iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
int length(node *head) {
   if (head == NULL) 
        return 0;  
    return 1 + length(head->next);
}
node* midpoint_linkedlist(node *head)
{
	node * slow=head;
	node * fast= head->next;
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(temp!= NULL){
    	while(fast!= NULL && fast->next!=NULL){
    		slow=slow->next;
    		fast = fast->next->next;
		}
		return slow;
}
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}



