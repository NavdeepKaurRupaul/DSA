#include <iostream>
using namespace std;
int MissingNumber(int arr[], int size){
	int SumOfArrayElemets=0;
 for(int i = 0; i < size; i++) {
    SumOfArrayElemets=SumOfArrayElemets+arr[i];
}
int n = size;
int SumOfNaturalNum = ((n-2)*(n-1))/2;
return SumOfArrayElemets-SumOfNaturalNum;
}
int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;
}

