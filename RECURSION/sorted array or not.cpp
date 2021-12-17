#include<iostream>
using namespace std;
bool sorted(int a[], int size){
	if(size==0|| size==1){
		return true;
	}
	if(a[0]>a[1]){
		return false;
	}
	int smallersorted=sorted(a+1,size-1);
	if(smallersorted){
		return true;
	}
}
int main(){
	int n;
	cout<<"enter array size";
	cin>>n;
	int array[100];
	for(int i=0;i<n;i++){
	cin>>array[i];
    }
    if(sorted(array,n)){
    	cout<<"true"<<endl;
	}
	else{
		cout<<"false";
	}
}
