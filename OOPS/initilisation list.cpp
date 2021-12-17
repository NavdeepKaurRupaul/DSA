#include<iostream>
using namespace std;
class student{
	public:
		int age;
		int &a; //reference of age
		const int rollno;
		student(int r,int age):rollno(r),age(age),a(this->age){
		}
		void display(){
			cout<<rollno<<" "<<age<<" "<<a<<endl;
		}
};
int main(){
	student s1(105,21);
	s1.age=21;
	s1.display();
}
