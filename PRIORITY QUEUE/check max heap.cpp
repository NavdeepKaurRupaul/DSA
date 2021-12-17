#include <iostream>
using namespace std;
bool isHeap(int arr[], int i, int n) { 
     if (i > (n - 2)/2){
    	return true; 
     }    
     if (arr[i] >= arr[2*i + 1] && arr[i] >= arr[2*i + 2] && isHeap(arr, 2*i + 1, n) && isHeap(arr, 2*i + 2, n)) {
      	return true; 
     } 
     return false; 
} 
bool checkMaxHeap(int arr[], int n){
	return isHeap(arr,0,n);
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }    
    delete [] arr;
}

