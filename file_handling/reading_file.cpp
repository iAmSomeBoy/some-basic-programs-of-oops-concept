#include <iostream>
#include <fstream>
using namespace std;

int main(){

fstream fileName;
    fileName.open("fileName.txt", ios:: in);
    if(!fileName){
        cout<<"File Reading Failed or File doesn't exits"<<endl;
    }
    else{
        char x;
        while(1){
            fileName>>x;
            if(fileName.eof()){
                break;
            }
            cout<<x;
        }
        fileName.close();
    }

    return 0;
}

//https://www.mygreatlearning.com/blog/file-handling-in-cpp/