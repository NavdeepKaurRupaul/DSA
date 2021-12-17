#include<iostream>
using namespace std;
template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};
template<typename T>
class Queue {  
    Node<T> *head;
	Node<T> *tail;
	int size; 
    public :   
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }   
    void enqueue(T data) {
    	Node<T> *newnode=new Node<T>(data);
        if(head==NULL){
        	head=newnode;
        	tail=newnode;
        	size++;
		}
		else{
			tail->next=newnode;
			tail=newnode;
			size++;	
		}
    }  
	 
    int getSize() {
        if(head==NULL){
        	cout<<"QUEUE EMPTY!"<<endl;
        	return 0;
		}
		else{
			return size;
		}
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
        if(head==NULL){
        	cout<<"QUEUE EMPTY!"<<endl;
        	return 0;
		}
		else{
			T a= head->data;
			Node<T>* temp=head;
			head=head->next;
			delete temp;
			size--;
			return a;
		}
    }
    
    T front()  {
        if(head==NULL){
        	cout<<"QUEUE EMPTY!"<<endl;
        	return 0;
		}
		else{
			return head->data;
		}
    }
};

int main() {  
    Queue<int> q;  
    int choice;
    cin >> choice;
    int input;  
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }  
}

