#include<iostream>
using namespace std;
#include<cstring>
#include<stack>
bool checkBalanced(char *exp) {
    stack<char> s;
    char x;
    for(int i=0;i<strlen(exp);i++){
    	if (exp[i]=='('||exp[i]=='['||exp[i]=='{') { 
            s.push(exp[i]);
        } 
       else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
       {
           if (s.empty())
        return false; 
        char t=s.top();
        if(exp[i]==')' && t=='(')
        {
            s.pop();
        }
        else if(exp[i]=='}' && t=='{')
        {
            s.pop();
        }
         else if(exp[i]==']' && t=='[')
        {
            s.pop();
        }
        else
        {
            return false;
        }
        }
        

       }
        
if(s.empty())
{
    return true;
}
        else{
            return false;
        }
            
}   
int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

