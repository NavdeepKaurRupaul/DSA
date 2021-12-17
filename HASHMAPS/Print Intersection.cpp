#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
void intersection(int input1[], int input2[], int size1, int size2) {
	unordered_map<int,int> map1;
	unordered_map<int,int> map2;
	for(int i=0;i<size1;i++){
		map1[input1[i]]=input1[i];
	}
	for(int i=0;i<size2;i++){
		map2[input2[i]]=input2[i];
	}
	int maximun = max(size1, size2);
	for(int i=0;i<maximun;i++){
		for(int j=0;j<maximun;j++){
			if(map1[input1[i]]==map2[input2[j]]){
				cout<<map1[input1[i]]<<endl;
				map2[input2[j]]=INT_MIN;
				break;			    
		}
		}	
	}
}
int main() {
	int size1,size2;
	cin>>size1;
	int *input1=new int[1+size1];		
	for(int i=0;i<size1;i++)
		cin>>input1[i];
	cin>>size2;
	int *input2=new int[1+size2];		
	for(int i=0;i<size2;i++)
		cin>>input2[i];	
	intersection(input1,input2,size1,size2);		
	return 0;
}

