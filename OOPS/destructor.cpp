#include<iostream>
using namespace std;
class student{
	public:
		int rollno;
		int age;
		student(){
	    cout<<"cnstructor1 called!"<<endl;
		}
		student(int r){
			cout<<"constructor2 called!"<<endl;
			rollno=r;
		}
		student(int a, int r){
			cout<<"constructor3 called!"<<endl;
			age=a;
			rollno=r;
		}
		~student(){
			cout<<"destructor called!"<<endl;
		}
		void display(){
			cout<<age<<" "<<rollno<<endl;
		}
};
int main(){
	student s1;
	s1.display();
	student s2(20);
	s2.display();
	student s3(20,105);
	s3.display();
	student * s4 = new student(10,105);
	delete s4; //to deallocate dynamically allocated s4
}
