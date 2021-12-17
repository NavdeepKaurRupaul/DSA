#include<iostream>
using namespace std;
#include<algorithm>
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
    int max_len = 0;
    for (int i = 0; i < size; i++) { 
        int curr_sum = 0; 
        for (int j = i; j < size; j++) { 
            curr_sum += arr[j]; 
            if (curr_sum == 0) 
                max_len = max(max_len, j - i + 1); 
        } 
    } 
    return max_len;
}

int main(){
  int size;
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}



