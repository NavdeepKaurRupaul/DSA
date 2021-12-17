#include<iostream>
using namespace std;
#include <vector>
#include<climits> 
vector<int> kSmallest(int *input, int n, int k) {
	vector<int> output;
	 for(int i=0;i<k;i++){
	 	output.push_back(input[i]);
	 }
	 for(int i=k;i<n;i++){
	 	int maxElement=INT_MIN;
	 	int maxElementIndex=0;
	 	for(int i=0;i<k;i++){
	 		if(output[i]>maxElement){
	 			maxElement = output[i];
	 			maxElementIndex=i;
			 }
		 }
	 	if(maxElement > input[i]){
	 		output[maxElementIndex]=input[i];
		 }
	 }
	 return output;
}
int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	 kSmallest(input, n, k);
	//for(int i = 0; i < output.size(); i++){
	//	cout << output[i] << endl;
	//}
}

