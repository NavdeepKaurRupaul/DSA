#include<iostream>
using namespace std;
int main(){
	int a[10];
	cout<<a<<endl;
	cout<<&a<<endl;
	cout<<&a[0]<<endl;
	int *p= &a[0];
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(p)<<endl;
}
