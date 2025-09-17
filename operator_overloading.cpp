#include <iostream>
using namespace std;

class Complex{
    int real;
    int imag;

    public:
        Complex(){
            real = 0;
            imag = 0;
        }

        Complex(int r, int i){
            real = r;
            imag = i;
        }

        void display(){
            cout<<real <<" +"<<imag<<"i"<<endl;
        }

        Complex operator +(Complex c){
            Complex temp;
            temp.real = real+ c.real ;
            temp.imag = imag+ c.imag ;

            return temp;
        }

};

int main(){

    Complex c1(2, 4);
    Complex c2(4, 7);
    Complex c3(4,6);
    Complex c5;

    c5 = c1+ c2+ c3;
    c5.display();

    return 0;
}