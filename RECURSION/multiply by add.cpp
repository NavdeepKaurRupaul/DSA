#include <iostream>
using namespace std;
int multiplyNumbers(int m, int n) {
 if(n==0){
 	return 0;
 }
 int ans =m;
 int small=multiplyNumbers(m,n-1);
 return small+ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}

