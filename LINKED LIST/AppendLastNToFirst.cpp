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
node* getNthNodeFromEnd(node* head,int n)
{
	node* slow=head;
	node* fast=head;
	for(int i=0;i<n;i++)
		fast=fast->next;

	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;	
}
node* append_LinkedList(node* head,int n)
{
	node* prev=getNthNodeFromEnd(head,n);
	node* current=prev->next;
	prev->next=NULL;
	node* end=current;
	while(end->next!=NULL)
		end=end->next;
	end->next=head;

	return current;
    
}

int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}

