#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    /* create temp arrays */
    int L[n1], R[n2]; 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) //array of left hand side elements to mid element
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; //array of right handside elements to mid element
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergesort(int input[], int start, int end){
	if(start>=end){
		return;
	}
	int mid = (start+end)/2;
	mergesort(input,start,mid);
	mergesort(input,mid+1,end);
	merge(input,start,mid,end);
}
void mergeSort(int input[], int size){
       int start=0;
	   int end=size-1;
	   mergesort(input,start,end); 
}
void intersection(int input1[], int input2[], int size1, int size2) {
    mergeSort(input1,size1);
    mergeSort(input2,size2);
    int i=0;
    int j=0;
    while(i<size1 || j<size2){
	if(input1[i]==input2[j]){
    	cout<<input1[i]<<endl;
    	i++;
    	j++;
	}
	else if(input1[i]>input2[j]){
		j++;
	}
	else if(input1[i]<input2[j]){
		i++;
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

