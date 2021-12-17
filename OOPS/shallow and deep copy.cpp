#include<iostream>
#include<cstring>
using namespace std;
class student{
	int age;
	char * name;
	public:
		student(int age,char* name){
			this->age=age;
			//this->name=name; //SHALLOW COPY
			this->name= new char[strlen(name+1)]; //DEEP COPY
			;strcpy(this->name,name);
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
}
