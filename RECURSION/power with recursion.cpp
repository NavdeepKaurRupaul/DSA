#include<iostream>
#include<cmath>
using namespace std;
int power(int x, int n) {
if(n==0){
	return 1;
}
int smallpower=pow(x,(n-1));
return x*smallpower;

}

int main(){
    int x, n;
    cin >> x >> n;
    cout << power(x, n)<<endl ;
}



