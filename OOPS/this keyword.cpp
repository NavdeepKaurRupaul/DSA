#include<iostream>
using namespace std;
class student{
	public:
		int rollno;
		int age;
		student(){
	    cout<<"cnstructor1 called!"<<endl;
		}
		student(int rollno){
			cout<<"constructor2 called!"<<endl;
			this->rollno=rollno;
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
	student s1;
	s1.display();
	student s2(20);
	s2.display();
	student s3(20,105);
	s3.display();
}
