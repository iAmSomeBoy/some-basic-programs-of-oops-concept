//polymorphism.
#include <iostream>
using namespace std;

class Parent{
    public:
        virtual void getInfo(){
            cout<<"Parent class"<<endl;
        }
};

class Child: public Parent{
    public:
        void getInfo(){
            cout<<"Child Class"<<endl;
        }
};

int main(){

    Parent one;
    one.getInfo();

    Child two;
    two.getInfo();

    return 0;
}