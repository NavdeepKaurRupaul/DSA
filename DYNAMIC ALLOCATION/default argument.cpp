#include<iostream>
using namespace std;
int sum(int a,int b, int c=0){
	return a+b+c;
}
int main(){
	int a=10,b=20,c=30;
	cout<<sum(a,b,c)<<endl;
	int x=100,y=200;
	cout<<sum(x,y);
}
