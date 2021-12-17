#include <iostream>
using namespace std;
#include"student.cpp"
int main(){
	student s1;
	s1.rollno=105;
	s1.age=21;
	
	student* s2 =new student;
	(*s2).rollno=106;
	(*s2).age=21;
	/* or
	s2 -> rollno=106;
	s2 -> age =106;
	*/
	cout<<s1.rollno<<" "<<s1.age<<endl;
	cout<<(*s2).rollno<<" "<<(*s2).age<<endl;
}
