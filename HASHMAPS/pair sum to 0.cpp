#include<iostream>
using namespace std;
#include<unordered_map>	
 	#include<unordered_map>
	void PairSum(int *input, int n) {	 
     	unordered_map<int,int> map;
      for(int i=0;i<n;i++){
        map[input[i]]++;
      }
      for(int i=0;i<n;i++){
        if(map[input[i]]>0){
          if(map[0-input[i]]>0){
            int count=map[input[i]]*map[0-input[i]];
            map[input[i]]=0;
            map[0-input[i]]=0;
            int a,b;
            if(input[i]>0){
              a=input[i];
              b=0-(input[i]);
            }
            else{
              b=input[i];
              a=0-input[i];
            }
            while(count>0){
              cout<<b<<" "<<a<<endl;
              count--;
            }
          }
        }
      }	
 	}
int main(){
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

