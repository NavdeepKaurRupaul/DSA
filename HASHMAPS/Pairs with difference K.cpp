#include<iostream>
using namespace std;
#include<unordered_map>

#include<unordered_map>
#include<cmath>
void printPairs(int *input, int n, int k) {
  unordered_map<int,int> map;
  for(int i=0;i<n;i++){
    map[input[i]]++;
  }
  for(int i=0;i<n;i++){
    if(map[input[i]]>0){
      map[input[i]]--;
      if(map[input[i]-k]>0){
        
        int count=map[(input[i]-k)];
        while(count>0){
          int a=min(input[i]-k,input[i]);
          int b=max(input[i]-k,input[i]);
          cout<<a<<" "<< b <<endl;
          count--;
        }
      }
     if(k!=0){
      if(map[input[i]+k]>0){
        int count=map[(input[i]+k)];
        while(count>0){
          int a=min(input[i]+k,input[i]);
          int b=max(input[i]+k,input[i]);
          cout<<a<<" "<< b << endl;
          count--;
        }
      }
     }
    }
  }
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

