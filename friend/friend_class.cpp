#include <iostream>
using namespace std;

class ClassB;  // Forward declaration of ClassB

class ClassA {
 private:
  int dataA;

 public:
  ClassA() : dataA(42) {}  // Initialize dataA with a value

  // Declare ClassB as a friend of ClassA
  friend class ClassB;
};

class ClassB {
 public:
  void showDataFromA(const ClassA& objA) {
    // Access private member of ClassA
    cout << "Data from ClassA: " << objA.dataA << endl;
  }
};

int main() {
  ClassA objA;
  ClassB objB;

  // Use ClassB to access ClassA's private data
  objB.showDataFromA(objA);

  return 0;
}
