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
		void display(){
			cout<<age<<" "<<rollno<<endl;
		}
};
int main(){
	student s1; //constructor1 called
	s1.display();
	student s2(20); //constructor2 called
	s2.display();
	student s3(20,105); //constructor3 called
	s3.display();
	student s4(s3); //copy assignment constructor called
	s4.display();
	student s5; //constructor1 called
	s5=s4; //no constructor is called       copy assignment operator is used
	s5.display();
	student s6 = s1; //copy constructor is called
}
