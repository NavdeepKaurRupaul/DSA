#include<iostream>
using namespace std;
int stringlenght(char str[]){
	if(str[0]=='\0'){
		return 0;
	}
	int smalllength = stringlenght(str+1);
	return 1+smalllength;
}
int main(){
	char str[100];
	cin>>str;
	int l=stringlenght(str);
	cout<<l<<endl;
}
