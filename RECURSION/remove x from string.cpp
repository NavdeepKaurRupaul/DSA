#include<iostream>
using namespace std;
void removeX(char string[]){
	if(string[0]=='\0'){
		return;
	}
	if(string[0]!='x'){
		removeX(string+1);
	}
	else{
		int i=1;
		for(;string[i]!='\0';i++){
			string[i-1]=string[i];
		}
		string[i-1]=string[i]; //to copy null character
		removeX(string);
	}
}
int main(){
	char string[100];
	cin>>string;
	removeX(string);
	cout<<string;
}
