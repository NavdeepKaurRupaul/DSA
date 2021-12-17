#include<iostream>
using namespace std;
int main(){
int a = 7;
int b = 17;
int *c = &b; 
a = *c;
*c = *c + 1;
cout  << a << "  " << b << endl;
}
