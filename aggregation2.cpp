// Aggregation Example: Teacher aggregates Students
#include <iostream>
#include <string>
#include <vector>
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


class Student {
private:
    string name;
public:
    Student(string studentName) : name(studentName) {}
    string getName() const { return name; }
};

class Teacher {
private:
    string name;
    vector<Student*> students; // Aggregation: Teacher has Students, but does not own them
public:
    Teacher(string teacherName) : name(teacherName) {}
    string getName() const { return name; }

    // Add a student to the teacher's list
    void addStudent(Student* student) {
        students.push_back(student);
    }

    // Show all students taught by this teacher
    void showStudents() const {
        cout << "Teacher: " << name << " teaches:" << endl;
        for (const auto& student : students) {
            cout << "  - " << student->getName() << endl;
        }
    }
};

int main() {
    // Create students independently
    Student student1("Rahul");
    Student student2("Priya");
    Student student3("Amit");

    // Create teacher independently
    Teacher teacher1("Mr. Sharma");

    // Aggregate students to teacher
    teacher1.addStudent(&student1);
    teacher1.addStudent(&student2);
    teacher1.addStudent(&student3);

    // Show aggregation
    teacher1.showStudents();

    // Students exist independently of teacher
    cout << "Student: " << student2.getName() << " exists even if teacher is deleted." << endl;

    return 0;
}