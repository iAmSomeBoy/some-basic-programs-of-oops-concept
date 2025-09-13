#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
public:
    Student(string studentName) : name(studentName) {
        cout << "Student " << name << " created." << endl;
    }
    string getName() const { return name; }
    ~Student() {
        cout << "Student " << name << " destroyed." << endl;
    }
};

class Teacher {
private:
    string name;
    Student student; // Composition: Teacher owns Student
public:
    Teacher(string teacherName, string studentName)
        : name(teacherName), student(studentName) {
        cout << "Teacher " << name << " created." << endl;
    }
    void showStudent() const {
        cout << "Teacher: " << name << " teaches " << student.getName() << endl;
    }
    ~Teacher() {
        cout << "Teacher " << name << " destroyed." << endl;
    }
};

int main() {
    Teacher teacher1("Mr. Sharma", "Rahul");
    teacher1.showStudent();

    // When teacher1 goes out of scope, both teacher1 and student are destroyed automatically
    return 0;
}