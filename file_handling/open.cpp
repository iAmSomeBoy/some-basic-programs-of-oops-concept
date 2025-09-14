#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream file1;

    file1.open("file1.txt",ios:: out);
    if(!file1){
        cout<<"Error whiling creating the file"<<endl;
    }
    else{
        cout<<"Files are created and got written"<<endl;
        file1<<"This text is being pushed into the file";
        file1.close();
    }

    
    return 0;
}