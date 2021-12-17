#include <iostream>
using namespace std;
int FindSortedArrayRotation(int arr[], int n) {
	for(int i=0;i<n;i++){
		if(arr[i]>arr[i+1]){
			return i+1;
		}
		else{
			return 0;
		}
	}
}
int main() {
	int size;
	cin>>size;
	int *input=new int[1+size];		
	for(int i=0;i<size;i++)
		cin>>input[i];	
	cout<<FindSortedArrayRotation(input,size);
	return 0;
}

