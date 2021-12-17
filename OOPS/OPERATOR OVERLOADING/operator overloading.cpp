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
		// + OPERATOR OVERLOADING
		fraction operator+(fraction const &f){
			int lcm = denominator * f.denominator;
			int x = lcm / denominator;
			int y = lcm / f.denominator;
			int num = x * numerator + (y * f.numerator);
			fraction fNew(num, lcm);
			fNew.simplify();
			return fNew;
		}
		// * OPERATOR OVERLOADING
		fraction operator*(fraction const &f){
			int den = denominator*f.denominator;
			int num = numerator*f.numerator;
			fraction fNew(num, den);
			fNew.simplify();
			return fNew;
		}
		// == OPERATOR OVERLOADING
		bool operator==(fraction f){
			return(numerator==f.numerator && denominator==f.denominator);
		}
};
int main(){
	fraction f1(10,2);
	fraction f2(20,4);
	fraction f3=f1+(f2);
	f3.print();
	fraction f4=f1*(f2);
	f4.print();
	if(f4==f3){
		cout<<"equal"<<endl;
	}
	else{
		cout<<"not equal"<<endl;
	}
}
