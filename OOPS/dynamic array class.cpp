#include<iostream>
using namespace std;
class dynamicarray{
	int *data;
	int nextindex;
	int capacity;
	public:
		dynamicarray(){
			data=new int[5];
			capacity=5;
			nextindex=0;
		}
		//TO ADD ELEMENT
		void add(int element){
			if(nextindex==capacity){
				int *newdata= new int[2*capacity];
				for(int i=0;i<nextindex;i++){
					newdata[i]=data[i];
				}
				delete [] data;
				data=newdata;
				capacity= 2*capacity;
			}
			else{
				data[nextindex]=element;
				nextindex++;
			}
		}
		//TO ADD ELEMENT AT Ith INDEX 
		void addelement(int i,int element){
			if(i<nextindex){
				data[i]=element;
			}
			else if(i==nextindex){
				add(element);
			}
			else{
				return;
			}
		}
		//TO PRINT
		void print(){
			for(int i=0;i<nextindex;i++){
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
		//COPY CONSTRUCTOR
		dynamicarray(dynamicarray const &d){
			this -> data = new int[d.capacity];
		    for(int i = 0; i < d.nextindex; i++) {
			this -> data[i] = d.data[i];
		    }
		this -> nextindex = d.nextindex;
		this -> capacity = d.capacity;
		}
		//= operator overloading(copy assignment operator)
		void operator=(dynamicarray const &d){
			this -> data = new int[d.capacity];
		    for(int i = 0; i < d.nextindex; i++) {
			this -> data[i] = d.data[i];
		    }
		this -> nextindex = d.nextindex;
		this -> capacity = d.capacity;
		}
};
int main(){
    dynamicarray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);
	d1.print();	
	dynamicarray d2(d1);		// Copy constructor
	dynamicarray d3;
	d3 = d1;
	d1.addelement(0, 100);
	cout<<"d1"<<endl;
	d1.print();
	cout<<"d2"<<endl;
	d2.print();
	cout<<"d3"<<endl;
	d3.print();
}
