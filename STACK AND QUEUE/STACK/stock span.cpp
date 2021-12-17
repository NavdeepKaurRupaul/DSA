#include <iostream>
using namespace std;
void calculateSpan(int price[], int n, int S[])  {  
    // Span value of first day is always 1  
    S[0] = 1;  
    // Calculate span value of remaining days by linearly checking previous days  
    for (int i = 1; i < n; i++)  
    {  
        S[i] = 1; // Initialize span value  
        // Traverse left while the next element on left is smaller than price[i]  
        for (int j = i - 1; (j >= 0) &&  (price[i] > price[j]); j--)  
            S[i]++;  
    }  
} 
int* stockSpan(int *price, int size) {
	int *array=new int[size];
	calculateSpan(price,size,array);
	return array;
}

int main() {
    int size;
    cin >> size;
    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

