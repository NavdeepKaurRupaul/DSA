#include<iostream>
using namespace std;
void increment(int *p){
	(*p)++;
}
int main(){
	int a=10;
	int*p=&a;
	increment(p);
	cout<<a;
}
