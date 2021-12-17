#include<iostream>
using namespace std;
#include<queue>
int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	q.push(90);
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	cout<<q.size()<<endl;
	q.pop();
	q.pop();
	cout<<q.front();
}
