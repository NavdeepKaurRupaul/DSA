#include <iostream>
using namespace std;
int binarysearch(int arr[], int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
        return binarysearch(arr, l, mid - 1, x);  
            
        return binarysearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
int binarySearch(int input[], int size, int element){
	int start=0;
	int end=size-1;
	return binarysearch(input,start,end,element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++) { 
        cin >> input[i];;
    }
    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

