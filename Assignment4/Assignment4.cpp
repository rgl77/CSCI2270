#include "CommunicationNetwork.h"
#include <string>
#include <iostream>
#include <fstream>
// Orgil Sugar
// Rhonda
// Aayush
// Thursday 8 AM
using namespace std;

int main(int argc, char* argv[]){
    string x ;
    CommunicationNetwork A;

    while(x != "5"){
        cout	<<	"======Main Menu======"	<<	endl;
        cout	<<	"1.Build Network"	<<	endl;
        cout	<<	"2.Print Network Path"	<<	endl;
        cout	<<	"3.Transmit Message Coast-To-Coast"	<<	endl;
        cout	<<	"4.Add	City"	<<	endl;
        cout	<<	"5.Quit"	<< endl;
        getline(cin,x);
        if( x == "1"){
            A.buildNetwork();
            }
        else if( x == "2"){
             A.printNetwork();
        }
        else if( x == "3"){

             char* filename = argv[1];
             A.transmitMsg(filename);
        }
        else if( x == "4"){
                string nam,pre;
                cout << "Enter a city name:" << endl;
                getline(cin,nam);
                cout << "Enter a previous city name:" << endl;
                getline(cin,pre);
                A.addCity(nam,pre);
        }


    }

        cout<<"Goodbye!"<<endl;
}
