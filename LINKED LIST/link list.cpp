#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int data){
			this->data=data;
			next=NULL;
		}
};
int main(){
	//statically
	node n1(1);
	node *head=&n1;  //to store address of head node
	node n2(2);
	n1.next=&n2;
	//dynamically
	node *n3=new node(10);
	node *n4=new node(20);
	n2.next=n3;
	n3->next=n4;
	cout<<"NODE 1: ";
	cout<<n1.data<<" "<<n1.next<<endl;
	cout<<"NODE 2: ";
	cout<<n2.data<<" "<<n2.next<<endl;
	cout<<"NODE 3: ";
	cout<<n3->data<<" "<<n3->next<<endl;
	cout<<"NODE 4: ";
	cout<<n4->data<<" "<<n4->next<<endl;
	cout<<"printing vluses of n1 by using head :";
	cout<<head->data<<" "<<head->next<<endl;
}
