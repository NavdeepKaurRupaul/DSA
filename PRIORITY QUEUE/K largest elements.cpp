#include <iostream>
using namespace std;
#include<vector>
#include<climits>
vector<int> kLargest(int input[], int n, int k){
	vector<int> output;
	for(int i=0;i<k;i++){
		output.push_back(input[i]);
	}
	for(int i =k;i<n;i++){
		int minElement = INT_MAX;
		int minElementIndex = 0;
		for(int i=0;i<k;i++){
			if(output[i]<minElement){
				minElement = output[i];
				minElementIndex=i;
			}
		}
		if(minElement<input[i]){
			output[minElementIndex]=input[i];
		}
	}
	return output;
}

int main() {	
	int size;
	cin >> size;
	int *input = new int[1 + size];	
	for(int i = 0; i < size; i++)
		cin >> input[i]; 
    int k;
    cin >> k;   
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;	
	return 0;
}

