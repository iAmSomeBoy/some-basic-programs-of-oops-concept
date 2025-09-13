/* 
#include <iostream>
using namespace std;

class Student{
    private:
        string name;
    public:
        Student(string sName): name(sName){}
        string getName() const{
            return name;
        }
};

class Teacher{
    private:
        string name;
        Student student;
    public:
        Teacher(string tName, string sName): name(tName), student(sName){
            cout<<"Teacher "<<name<<" created."<<endl;
        }

        void showData() const{
            cout<<"Teacher: "<<name<<" teaches "<<student.getName()<<endl;
        }

        ~Teacher(){
            cout<<"Teacher "<<name<<" destroyed"<<endl;
        }
    
};

int main(){

    Teacher teacher("Jone Doe","Ruhul");
    teacher.showData();


    return 0;
}
*/



/*
#include <iostream>
using namespace std;

class Student{
    private:
        string name;
    public:
        Student(string sName):name(sName){}

        string getData() const{
            return name;
        }

};

class Teacher{
    private:
        string name;
        Student student;
    public:
        Teacher(string tName, string sName): name(tName), student(sName){}
        

        void showData(){
            cout<<"Teacher name: "<<name<<", "<<"Student name: "<<student.getData()<<endl;
        }
};

int main(){
    Teacher teacher1("Jone Doe", "Jakey");
    teacher1.showData();

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string name;
    public:
        Student(string sName): name(sName){}

        string getName(){
            return name;
        }
};

class Classroom{
    private:
    string roomNumber;
    vector<Student*>student;

    public:
        Classroom(string No): roomNumber(No){}

        void addStudent(Student* add){
            student.push_back(add);
        }

        void studentList(){
            for(auto List:student){
                cout<< List -> getName()<<endl;
            }
        }
};

int main(){
    Student student1("ABCD");
    Student student2("EFGH");

    Classroom math("Math 159");
    math.addStudent(&student1);
    math.addStudent(&student2);
    math.studentList();
    return 0;
}*/

/*Classroom mathClass("M101");
    mathClass.addStudent(&student1);
    mathClass.addStudent(&student2);
    
    mathClass.listStudents();
    */


//##################################################////
                   //-- aggregation --//

#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
    string name;

    public:
        Student(string sName): name(sName){
            cout<<"Name Pushed into Student Class"<<endl;
        }

        string getName(){
            return name;
        }
};

class Classroom{
    private:
        string name;
        vector<Student*>students;
    public:
        Classroom(string cName): name(cName){
            cout<<"Name Pushed into ClassRoom"<<endl;
        }
        
        void addList(Student* viz){
            students.push_back(viz);
        }

        void PrintList(){
            for(auto l : students){
                cout<<l->getName()<<endl;
            }
        }
};

int main(){
    Student student1("asdf"), student2("hgfdsa");
    Classroom math("EDC159");
    math.addList(&student1);
    math.addList(&student2);

    math.PrintList();


    return 0;
}