#include <iostream>
using namespace std;
int sumOfDigits(int n) {
if(n<=0){
	return 0;
}
int sum = n%10;
 int sumrecursion =sumOfDigits(n/10);
 return sum+sumrecursion;
}
int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}

