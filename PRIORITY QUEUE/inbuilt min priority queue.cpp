#include<iostream>
using namespace std;
#include<queue>
int main(){
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(100);
	pq.push(0);
	pq.push(1);
	pq.push(105);
	pq.push(21);
	pq.push(17);
	cout<<"SIZE: "<<pq.size()<<endl;
	cout<<"MAX: "<<pq.top()<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}
