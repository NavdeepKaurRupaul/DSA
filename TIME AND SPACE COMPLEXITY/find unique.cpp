#include<iostream>
#include <algorithm>
using namespace std;
int FindUnique(int * arr, int size){
      int val;
    for(int i=0;i<size;i++){
    	for(int j=0; j<size;j++){
            val=arr[i];
            //i!=j to not compare same number with it self
            if(i!=j){
    		if(val==arr[j]){
    			break;
			}
    	}
            if(j==size-1)
				return val;
    }
        
			}
}
int main() {
	int size;
	cin>>size;
	int *input=new int[1+size];		
	for(int i=0;i<size;i++)
		cin>>input[i];	
	cout<<FindUnique(input,size)<<endl;		
	return 0;
}

