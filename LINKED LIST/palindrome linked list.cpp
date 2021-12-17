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
void reverse(node** head_ref) 
{ 
    node* prev   = NULL; 
    node* current = *head_ref; 
    node* next; 
    while (current != NULL) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 

  
/* Function to check if two input lists have same data*/
bool compareLists(node* head1, node *head2) 
{ 
    node* temp1 = head1; 
    node* temp2 = head2; 
  
    while (temp1 && temp2) 
    { 
        if (temp1->data == temp2->data) 
        { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else return 0; 
    } 
  
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    /* Will reach here when one is NULL 
      and other is not */
    return 0; 
} 
  
bool check_palindrome(node* head)
{
     node *slow_ptr = head, *fast_ptr = head; 
    node *second_half, *prev_of_slow_ptr = head; 
     node *midnode = NULL;  // To handle odd size list 
    bool res = true; // initialize result 
  
    if (head!=NULL && head->next!=NULL) 
    { 
        /* Get the middle of the list. Move slow_ptr by 1 
          and fast_ptrr by 2, slow_ptr will have the middle 
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) 
        { 
            fast_ptr = fast_ptr->next->next; 
  
            /*We need previous of the slow_ptr for 
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
  
        /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
        if (fast_ptr != NULL) 
        { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half);  // Reverse the second half 
        res = compareLists(head, second_half); // compare 
  
        /* Construct the original list back */
         reverse(&second_half); // Reverse the second half again 
  
          // If there was a mid node (odd size case) which                                                          
         // was not part of either first half or second half. 
         if (midnode != NULL)  
         { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
         } 
         else  prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
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
int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}

