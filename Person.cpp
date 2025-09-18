#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string Name;
    int age;

public:
    Person() {}
    Person(string n, int a) {
        Name = n;
        age = a;
    }

    void inputPerson() {
        cout << "Enter Name: ";
        getline(cin, Name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPerson() {
        cout << "Name: " << Name << endl;
        cout << "Age: " << age << endl;
    }
};

// Aggregated class
class Course {
private:
    int courseCode;
    float credit;

public:
    Course() {}
    Course(int code, float cr) {
        courseCode = code;
        credit = cr;
    }

    void inputCourse() {
        cout << "Enter Course Code: ";
        cin >> courseCode;
        cout << "Enter Course Credit: ";
        cin >> credit;
    }

    void displayCourse() {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Credit: " << credit << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int studentID;
    Course course;  // Aggregation

public:
    Student() {}

    void inputStudent() {
        cin.ignore();  // to clear input buffer
        inputPerson();

        cout << "Enter Student ID: ";
        cin >> studentID;

        course.inputCourse();
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        course.displayCourse();
    }
};

// Main function
int main() {
    Student s;
    s.inputStudent();
    cout << "\n--- Student Details ---\n";
    s.displayStudent();

    return 0;
}
