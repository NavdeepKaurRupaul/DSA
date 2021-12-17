#include <iostream>
#include<cstring>
using namespace std;
bool helper(char input[],int start,int end){
    if(start>=end){
        return true;
    }
 	if(input[start]!=input[end]){
		return false;
	}
    start++;
   end--;
	bool b= helper(input,start,end);
    if(b){
        return true;
    }
    else{
        return false;
    }
}
bool checkPalindrome(char input[]) {
	 int len =strlen(input);
	 helper(input,0,len-1);
}


int main() {
    char input[50];
    cin >> input;
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

