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
		fraction& operator+=(fraction const &f){
			int lcm = denominator*f.denominator;
			int x = lcm/denominator;
			int y= lcm/f.denominator;
			int num= x*numerator+y*f.numerator;
			int den= lcm;
			numerator=num;
			denominator=den;
			simplify();
			return *this;
		}
};
int main(){
	fraction f1(10,3);
	fraction f2(5,2);
	f1+=f2;
	f1.print();
}
