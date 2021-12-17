#include<iostream>
using namespace std;
int main(){
	int i=10;
	int *p=&i;
	cout<<p<<endl;//address of i will be printed
	cout<<sizeof(p)<<endl;//size of pointer will be printed
	
	cout<<i<<" OR by using pointer"<<" "<<*p<<endl;
	i++; //increment value of i by 1(10+1=11)
	cout<<i<<endl;
	(*p)++;//increment vaule of i by 1(11+1=12)
	cout<<*p<<endl;
}
