#include<iostream>
using namespace std;
class fraction{
	private:
		int numerator;
		int denominator;
	public:
		fraction(int num,int den){
			numerator=num;
			denominator=den;
		}
		void print(){
			cout<<numerator<<"/"<<denominator<<endl;
		}
		void simplify(){
			int j = min(numerator,denominator);
			int gcd=1;
			for(int i=1;i<=j;i++){
				if(numerator%i==0 && denominator%i==0){
					gcd=i;
				}
			}
			int num = numerator/gcd;
			int den = denominator/gcd;
			numerator=num;
			denominator=den;
		}
		void add(fraction const &f){
			int lcm = denominator*f.denominator;
			int x = lcm/denominator;
			int y= lcm/f.denominator;
			int num= x*numerator+y*f.numerator;
			int den= lcm;
			numerator=num;
			denominator=den;
			simplify();
		}
		void multiply(fraction const &f){
			int den = denominator*f.denominator;
			int num = numerator*f.numerator;
			numerator=num;
			denominator=den;
			simplify();
		}
};
int main(){
	fraction f1(10,2);
	cout<<"f1 values"<<endl;
	f1.print();
	fraction f2(15,4);
	cout<<"f2 values"<<endl;
	f2.print();
	f1.add(f2);
	cout<<"after addtion values"<<endl;
	cout<<"f1 values"<<endl;
	f1.print();
	cout<<"f2 values"<<endl;
	f2.print();
	f1.multiply(f2);
	cout<<"after multiplication values"<<endl;
	cout<<"f1 values"<<endl;
	f1.print();
	cout<<"f2 values"<<endl;
	f2.print();
}
