#include<iostream>
using namespace std;
void findIndexes(int input[], int size, int x, int output[], int &k, int currIndex){
	if(currIndex==size){
		return;
	}
	if(input[currIndex]==x){
		output[k] = currIndex;
		k++;
	}
	findIndexes(input,size,x,output,k,++currIndex);
}

int allIndexes(int input[], int size, int x, int output[]){
	int k = 0;
	findIndexes(input,size,x,output,k,0);
	return k;
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
    int *output = new int[n];
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    delete [] input;
    delete [] output;
}



