#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
int main(){
	unordered_map<string, int> o;
	o["abc1"]=1;
	o["abc2"]=2;
	o["abc3"]=3;
	o["abc4"]=4;
	o["abc5"]=5;
	o["abc6"]=6;
	//map iterator
	cout<<"MAP"<<endl;
	unordered_map<string, int> :: iterator it = o.begin();
	while(it != o.end()){
		cout<<"KEY:"<<it->first<<" "<<"VALUE:"<<it->second<<endl;
		it++;
	}
	cout<<endl;
	//vector iterator
	cout<<"VECTOR ELEMENTS"<<endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>:: iterator itv=v.begin();
	while(itv != v.end()){
		cout<<*itv<<" ";
		itv++;
	}
	cout<<endl;
}
