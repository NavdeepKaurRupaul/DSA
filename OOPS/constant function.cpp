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
		//CONSTANT FUNCTION
		int getnum() const{
			return numerator;
		}
		//CONSTANT FUNCTION
		int getdeno() const{
			return denominator;
		}
		//CONSTANT FUNCTION
		void print() const{
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
	const fraction f(20,2);
	cout<<f.getnum()<<" "<<f.getdeno()<<endl;
}
