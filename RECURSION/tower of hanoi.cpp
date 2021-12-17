#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
	if(n==1){
		cout<<"a"<<" "<<"c"<<endl;
		return;
	}
	towerOfHanoi(n-1,source,destination,auxiliary);
	cout<<"a"<<" "<<"b"<<endl;
	towerOfHanoi(n-1,auxiliary,source,destination);
}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}

