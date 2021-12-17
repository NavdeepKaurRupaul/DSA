#include<iostream>
#include<cstring>
using namespace std;
void removeConsecutiveDuplicates(char string[]){
	int len = strlen(string);
	if(len<=1){
		return;
	}
	removeConsecutiveDuplicates(string+1);
	if(string[0]==string[1]){
		int i;
		for(i=0;string[i]!='\0';i++){
			string[i]=string[i+1];
		}
		string[i]=string[i+1];
	}
	else{
		return;
	}
}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
