#include<iostream>
using namespace std;
int factorial(int n){
	if(n==1){
		return 1;
	}
	int smalloutput =factorial(n-1);
	return n*smalloutput;
}
int main(){
	int n;
	cout<<"enter number"<<endl;
	cin>>n;
	int output =factorial(n);
	cout<<output<<endl;
}
