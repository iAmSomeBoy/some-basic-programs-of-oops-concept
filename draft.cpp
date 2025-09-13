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