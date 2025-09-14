#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string x;
    fstream fileName, file1;
    fileName.open("fileName.txt", ios::in);
    file1.open("file1.txt", ios::out);//'out' mood e open korle pre existing file's content erase hobe.
                                      //'app' mood e open korle just new text append hobe.
    if(!fileName.is_open()){
        cout<<"Failed whiling opening"<<endl;
    }
    else{
    while(getline(fileName,x)){
        file1<<x<<endl;
    }
    cout<<"Copyed Successfully"<<endl;
    }

    fileName.close();
    file1.close();

    return 0;
}



/*#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fs1, fs2;
    string line;

    fs1.open("e:/data.txt", ios::in);
    fs2.open("e:/data2.txt", ios::out);

    if(fs1.is_open()==0)
    {
        cout<<"Cannot open source file";
    }
    else
    {
        while(getline(fs1,line))
        {
            fs2<<line<<endl;
        }
        cout<<"File copied successfully";
    }
    fs1.close();
    fs2.close();
    return 0;
}
    \*/