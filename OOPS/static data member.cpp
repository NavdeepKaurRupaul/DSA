#include<iostream>
using namespace std;
class student{
	public:
		int age;
		int rollno;
		static int totalstudents;
		student(){
			totalstudents++;
		}
};
int student::totalstudents=0;
int main(){
	student s1,s2,s3,s4,s5;
	cout<<student::totalstudents<<endl;
}
