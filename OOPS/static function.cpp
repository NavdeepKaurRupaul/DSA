#include<iostream>
using namespace std;
class student{
	private:
		static int totalstudents;
	public:
		int age;
		int rollno;
		static int gettotalstudents(){
			return totalstudents;
		}
		student(){
			totalstudents++;
		}
};
int student::totalstudents=0;
int main(){
	student s1,s2,s3,s4;
	cout<<student::gettotalstudents()<<endl;
}
