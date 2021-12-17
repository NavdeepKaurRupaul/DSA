#include<iostream>
using namespace std;
class student{
	public:
		int rollno;
	private:
		int age;
	public:
    	void display(){
    		cout<<age<<" "<<rollno<<endl;
		}
		//READING PRIVATE PROPERTY
	    int getAge(){
	    	return age;
		}
		//WRITING PRIVATE PROPERTY
		int setAge(int a){
			age=a;
		}
};
int main(){
	student s1;
	s1.rollno=105;
	s1.setAge(21);
	s1.display();
	student* s2;
	s2-> rollno=106;
	s2->setAge(22);
	s2->display();
}
