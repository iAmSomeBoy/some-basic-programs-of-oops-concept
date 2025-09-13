#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    string type;
public:
    Engine(string t) : type(t) {
        cout << "Engine " << type << " created" << endl;
    }
    ~Engine() {
        cout << "Engine " << type << " destroyed" << endl;
    }
    void start() {
        cout << "Engine " << type << " started" << endl;
    }
};

class Car {
private:
    string model;
    Engine engine;  // Composition: Car HAS-A Engine (strong ownership)
public:
    Car(string m, string eType) : model(m), engine(eType) {
        cout << "Car " << model << " created" << endl;
    }
    ~Car() {
        cout << "Car " << model << " destroyed" << endl;
    }
    void drive() {
        cout << "Driving car " << model << endl;
        engine.start();
    }
};

int main() {
    Car myCar("Toyota", "V6");
    myCar.drive();
    // When myCar goes out of scope, both Car and Engine are destroyed
    return 0;
}