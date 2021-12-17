#include<iostream>
using namespace std;
int main(){
 int a = 50;
 int *p=&a;
 cout<<p<<endl;
 p++; //add 4 in value of p
 cout<<p<<endl;
 
 //in case of double
 double i=10.90;
 double *dp=&i;
 cout<<dp<<endl;
 dp++; //add 8 in value of dp(double = 8bytes)
 cout<<dp<<endl;
 
 //in case of character
 /*char b='f';
 char *cp=&b;
 cout<<cp<<endl;
 cp++; //add 1 in value of cp(char =1byte)
 cout<<cp<<endl;*/
 }
