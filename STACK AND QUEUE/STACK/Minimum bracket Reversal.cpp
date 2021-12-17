#include <iostream>
using namespace std;
#include<stack>
#include<cstring>
int countBracketReversals(char input[]){
	stack<char> s;
    int len = strlen(input);
    if(len%2 != 0){
    	return -1;
	}
	else{
		int i=0;
		while(input[i]!='\0'){
			if(input[i]=='{'){
				s.push(input[i]);
				i++;
			}
			else if(input[i]=='}' && s.empty()==0){
				s.push(input[i]);
				i++;
			}
			else if(!s.empty() && s.top()!= '}'){
				s.push(input[i]);
				i++;
			}
			else if(input[i]=='}' && s.top()=='{'){
				s.pop();
                i++;
			}
		}
	}
	int count = 0;
	while(!s.empty()){
	char c1=s.top();
	s.pop();
	char c2=s.top();
	s.pop();
	if(c1=c2){
		count++;
	}
	else{
		count+2;
	}
}
return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input)<< endl;
}
