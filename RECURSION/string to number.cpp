#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int stringToNumber(char input[]) {
	int len = strlen(input);
		char a ='0';
    	int c = a; //c has ascii value of zero
    if(len == 1){
    	int b = input[0];//b has ascii value of 0th index element
    	return b-c;
	}
	int small= stringToNumber(input+1);
	int b= input[0];
	int d = b-c;
	return d*pow(10,(len-1))+small;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

