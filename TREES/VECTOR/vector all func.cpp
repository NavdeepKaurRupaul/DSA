#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v;
	//to insert element
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	
	cout<<"BEFORE DELETING ELEMENT"<<endl;
	
	cout<<"SIZE:"<<v.size()<<endl;
	
	cout<<"CAPACITY:"<<v.capacity()<<endl;
	
	for(int i=0;i<v.size();i++){
		cout<<i<<" "<<"element -> "<<v.at(i)<<endl;
	}
	cout<<endl;
	
	//to delete element
	v.pop_back();
	v.pop_back();
	
	cout<<"AFTER DELETING ELEMENT"<<endl;
	
	cout<<"SIZE:"<<v.size()<<endl;
	
	cout<<"CAPACITY:"<<v.capacity()<<endl;
	
	for(int i=0;i<v.size();i++){
		cout<<i<<" "<<"element -> "<<v.at(i)<<endl;
	}
	cout<<endl;
	
	
	
}
