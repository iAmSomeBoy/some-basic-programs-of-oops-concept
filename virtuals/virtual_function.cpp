#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // Virtual function
        cout << "Some animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() { // Overriding virtual function
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() { // Overriding virtual function
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound(); // Output: Bark
    a2->sound(); // Output: Meow

    delete a1;
    delete a2;
    return 0;
}