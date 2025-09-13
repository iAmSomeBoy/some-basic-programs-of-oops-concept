// Aggregation Example: Teacher aggregates Students
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
public:
    Student(string n) : name(n) {
        cout << "Student " << name << " created" << endl;
    }
    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }
    string getName() const { return name; }
};

class Classroom {
private:
    string roomNumber;
    vector<Student*> students;  // Aggregation: Classroom HAS Students (weak ownership)
public:
    Classroom(string room) : roomNumber(room) {
        cout << "Classroom " << roomNumber << " created" << endl;
    }
    ~Classroom() {
        cout << "Classroom " << roomNumber << " destroyed" << endl;
    }
    void addStudent(Student* student) {
        students.push_back(student);
    }
    void listStudents() {
        cout << "Students in classroom " << roomNumber << ":" << endl;
        for (auto student : students) {
            cout << "- " << student->getName() << endl;
        }
    }
};

int main() {
    // Students exist independently
    Student student1("Alice");
    Student student2("Bob");
    
    Classroom mathClass("M101");
    mathClass.addStudent(&student1);
    mathClass.addStudent(&student2);
    
    mathClass.listStudents();
    
    // Students continue to exist even after classroom is destroyed
    return 0;
}