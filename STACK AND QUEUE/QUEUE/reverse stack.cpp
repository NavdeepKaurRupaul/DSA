#include <iostream>
using namespace std;
#include <stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==1||input.size()==0){
        return ;
    }
    int x= input.top();
    input.pop();
    
    reverseStack(input,extra);
    
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}
int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}

