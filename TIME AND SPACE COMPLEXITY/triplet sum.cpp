#include <iostream>
using namespace std;
void FindTriplet(int arr[], int size, int x) {
for(int i=0;i<size;i++){
	for(int j=i+1;j<size;j++){
		for(int k=j+1;k<size;k++){
			if(arr[i]+arr[j]+arr[k]==x){
				int a=arr[i];
				int b=arr[j];
				int c=arr[k];
				if(a<=b && a<=c){
					if(b<=c){
						cout<<a<<" "<<b<<" "<<c<<endl;
					}
					else{
						cout<<a<<" "<<c<<" "<<b<<endl;
					}
				}
				else if(b<=a && b<=c){
					if(a<=c){
						cout<<b<<" "<<a<<" "<<c<<endl;
					}
					else{
						cout<<b<<" "<<c<<" "<<a<<endl;
					}
				}
				else{
				if(a<=b){
						cout<<c<<" "<<a<<" "<<b<<endl;
					}
					else{
						cout<<c<<" "<<b<<" "<<a<<endl;
					}	
				}
			}
		}
	}
}
}
int main() {
	int size;
	int x;
	cin>>size;
	int *input=new int[1+size];		
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;
	FindTriplet(input,size,x);	
	return 0;
}


