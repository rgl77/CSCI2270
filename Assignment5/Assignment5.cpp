#include "CommunicationNetwork.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//Orgil Sugar
//TA; Aayush Grover
//Instructor: Rhonda Hoenigman

int main(int argc,char * argv[]){
    string x;
    CommunicationNetwork A;

    while( x != "7"){
    cout <<	"======Main Menu======"	<<	endl;
    cout <<	"1. Build Network"	<<	endl;
    cout <<	"2. Print Network Path"	<<	endl;
    cout <<	"3. Transmit Message Coast-To-Coast-To-Coast" << endl;
    cout <<	"4. Add City" << endl;
    cout <<	"5. Delete City" <<	endl;
    cout <<	"6. Clear Network" << endl;
    cout <<	"7. Quit" << endl;
    getline(cin,x);
    if(x=="1"){
        A.buildNetwork();
    }
    if(x=="2"){
        A.printNetwork();
    }
    if(x=="3"){
        char* filename = argv[1];
        A.transmitMsg(filename);
    }
    if(x=="4"){
        string nam,pre;
        cout << "Enter a city name: " << endl;
        getline(cin,nam);
        cout << "Enter a previous city name: " << endl;
        getline(cin,pre);
        A.addCity(nam,pre);
    }
    if(x=="5"){
        cout <<"Enter a city name: " << endl;
        string deleteC;
        getline(cin,deleteC);
        A.deleteCity(deleteC);
    }
    if(x=="6"){
        A.deleteNetwork();
    }
    }

    cout <<"Goodbye!"<<endl;
    A.deleteNetwork();
}
