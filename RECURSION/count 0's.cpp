#include <iostream>
using namespace std;
	int count =0;
int countZeros(int n) {
    if(n>0){
		if( (n% 10) == 0){
			count++;
		}
    int small=countZeros(n/10);
	}
	return count;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

