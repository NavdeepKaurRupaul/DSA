#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
vector<int> removeDuplicate(int* a, int size){
	unordered_map<int,bool> seen;
	vector<int> output;
	for(int i=0;i<size;i++){
		if(seen.count(a[i])>0){
			continue;
		}
		else{
			seen[a[i]]=true;
			output.push_back(a[i]);
		}
	}
	return output;
}
int main(){
	int a[]={1,2,3,2,1,5,4,1,3};
	vector<int> output = removeDuplicate(a,9);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
}
