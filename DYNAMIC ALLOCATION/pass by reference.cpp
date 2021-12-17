#include<iostream>
using namespace std;
void increment(int& n){
	n++;
}
int main(){
	int i=10;
	increment(i);
	cout<<i;
}
