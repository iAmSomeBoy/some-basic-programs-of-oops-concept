#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;

public:
    Teacher(string teacherName) : name(teacherName) {}

    string getName() {
        return name;
    }
};


// Student class
class Student {
private:
    string name;

public:
    Student(string studentName) : name(studentName) {}

    string getName() {
        return name;
    }

    // Method showing association with Teacher
    void showTeacher(Teacher &teacher) {
    cout << "Student: " << name << " is taught by Teacher: " << teacher.getName() << endl;
    }
};

int main() {
    // Create objects of Student and Teacher
    Student student1("Rahul");
    Teacher teacher1("Mr. Sharma");

    // Show association.
    student1.showTeacher(teacher1);

    return 0;
}    