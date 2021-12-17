#include <iostream>
using namespace std;
template<typename T>
class StackUsingArray {
	T *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray(){
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		/*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		*/

		return nextIndex == 0;
	}

	// insert element
	T push(int element) {
		if(nextIndex == capacity) {
			T *newdata=new T[2*capacity];
			for(int i=0;i<capacity;i++){
				newdata[i]=data[i];
			}
			capacity=capacity*2;
			delete[ ] data;
			data= newdata;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	T pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	T top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
		return data[nextIndex - 1];
	}
};
int main(){
	StackUsingArray<int> s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.push(500;


	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;

}
