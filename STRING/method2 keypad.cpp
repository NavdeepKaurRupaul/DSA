#include <iostream>
#include <string>
using namespace std;
void printkeypad(int num, string output){
	if(num==0){
		cout<<output<<endl;
	}
	printkeypad(num/10,output);
	int digit= num%10;
	if(digit==2){
		output[0]='a';
		output[1]='b';
		output[2]='c';
	}
		if(digit==3){
		output[0]='d';
		output[1]='e';
		output[2]='f';
	}
		if(digit==4){
		output[0]='g';
		output[1]='h';
		output[2]='i';
	}
		if(digit==5){
		output[0]='j';
		output[1]='k';
		output[2]='l';
	}
		if(digit==6){
		output[0]='m';
		output[1]='n';
		output[2]='o';
	}
		if(digit==27){
		output[0]='p';
		output[1]='q';
		output[2]='r';
		output[3]='s';
	}
		if(digit==8){
		output[0]='t';
		output[1]='u';
		output[2]='v';
	}
		if(digit==9){
		output[0]='w';
		output[1]='x';
		output[2]='y';
		output[3]='z';
	}
}
void printKeypad(int num){
	string output="";
	printkeypad(num,output);
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}

