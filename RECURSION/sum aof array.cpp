#include<iostream>
using namespace std;
int sum(int input[], int n) {
  if(n<0){
  	return 0;
  }
  int sum0=input[0];
  int smallsum=sum(input+1,n-1);
  return sum0+smallsum;
}

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << sum(input, n) << endl;
}



