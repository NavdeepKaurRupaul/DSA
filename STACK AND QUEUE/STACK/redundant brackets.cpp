#include <iostream>
using namespace std;
#include<cstring>
#include<stack>
bool checkRedundantBrackets(char *input) {
	stack<char> s;
	int len = strlen(input);
	for(int i=0;i<len;i++){
		if(input[i]!=')'){
            s.push(input[i]);
        }
        else if(input[i]==')'){
            int count=0;
            while(!s.empty()){
                char t=s.top();
                s.pop();
                if(t=='('){
                    break;
                }
                count++;
            }
            if(count==0)
                return true;
        }
}
}
int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}

