#include<iostream>
#include<cstring>
using namespace std;
class student{
	int age;
	public:
	char * name;
		student(int age,char* name){
			this->age=age;
			//this->name=name; //SHALLOW COPY
			this->name= new char[strlen(name)+1]; //DEEP COPY
			strcpy(this->name,name);
		}
		student(student const &s){
			this->age=s.age;
			this->name=new char [strlen(name)+1];
			strcpy(this->name,s.name);
		}
		void display(){
			cout<<name<<" "<<age<<endl;
		}
};
int main(){
	char name[]="NAVDEEP";
	student s1(21,name);
	s1.display();
	name[3]='\0';
	student s2(21,name);
	s2.display();
	s1.display();
	student s3(s1);
	s3.name[0]='n';
	s3.display();
}
