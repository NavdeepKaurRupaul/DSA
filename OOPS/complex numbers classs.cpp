#include<iostream>
using namespace std;
class ComplexNumbers {
	private:
		int real;
		int imaginary;
	public:
		ComplexNumbers(int re,int imag){
			real=re;
			imaginary=imag;
		}
		void plus(ComplexNumbers const &f){
			int re= real+f.real;
			int imag= imaginary+f.imaginary;
			real=re;
			imaginary=imag;
		}
		void multiply(ComplexNumbers const & f){
			int re = (real*f.real)-(imaginary*f.imaginary);
			int imag = real*f.imaginary+imaginary*f.real;
			real=re;
			imaginary=imag;
		}
		void print(){
			cout<<real<<" "<<"+"<<" "<<"i"<<imaginary<<endl;
		}
}; 
int main() {
    int real1, imaginary1, real2, imaginary2; 
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;  
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2); 
    int choice;
    cin >> choice;  
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    } 
}

