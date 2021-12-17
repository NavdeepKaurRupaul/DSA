#include<iostream>
using namespace std;
#include<unordered_map>
int highestFrequency(int *input, int n){
    unordered_map<int,int> output;
	for(int i=0;i<n;i++){
			output[input[i]]++;
	}	 
	int max = 0;
    int a=0;
	for(int i =0;i<n;i++){
		if(max < output[input[i]]){
			max = output[input[i]];
            a=input[i];
		}
	}
    return a;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}



