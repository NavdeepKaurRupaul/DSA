#include<iostream>
using namespace std;
bool checkNumber(int input[], int size, int x) {
 if(size==1){
 	if(input[0]==x){
 		return true;
 	}
 	//	else{
 	//		return false;
	//	 }
	 }
	 if(input [0]==x){
	 	return true;
	 }
	 int small=checkNumber(input+1,size-1,x);
	 if(small){
	 	return true;
	 }
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}



