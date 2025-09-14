#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream fileName ;
    fileName.open("fileName.txt", ios:: app);
    fileName<<". Append text is here";

    fileName.close();
    return 0;
}