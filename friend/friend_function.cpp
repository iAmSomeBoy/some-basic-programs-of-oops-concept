#include <iostream>
using namespace std;

class ClassName {
 private:
  int privateData;  // Private member

 protected:
  int protectedData;  // Protected member

 public:
  ClassName() : privateData(0), protectedData(0) {}

  // Declare a friend function
  friend void friendFunction(ClassName& obj);
};

// Friend function definition
void friendFunction(ClassName& obj) {
  obj.privateData = 42;    // Access private member
  obj.protectedData = 24;  // Access protected member
  cout << "Private Data: " << obj.privateData << endl;
  cout << "Protected Data: " << obj.protectedData << endl;
}

int main() {
  ClassName obj;
  friendFunction(obj);  // Call the friend function
  return 0;
}