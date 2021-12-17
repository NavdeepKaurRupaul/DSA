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
		// ++ OPERATOR OVERLOADING
		fraction& operator++(){
			numerator=numerator+denominator;
			simplify();
			return *this;
		}
};
int main(){
	fraction f1(10,2);
	f1.print();
	f1.operator++();
	f1.print();
	fraction f2=++(++f1);
	f2.print();
}
