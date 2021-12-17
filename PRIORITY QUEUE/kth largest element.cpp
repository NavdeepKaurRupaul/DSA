#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int kthLargest (vector<int> arr, int n, int k){
	priority_queue<int> p;
	for(int i =0;i<n;i++){
		p.push(arr[i]);
	}
	for(int i=0;i<k-1;i++){
		p.pop();
	}
	return p.top();
}

int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}

