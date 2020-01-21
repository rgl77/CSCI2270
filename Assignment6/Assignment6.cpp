#include <iostream>
#include "Queue.h"
#include <sstream>

using namespace std;
int main(){
    Queue A(10);

    string x;

    while (x != "5"){
        cout << "======Main Menu=====" << endl;
        cout << "1. Enqueue word" << endl;
        cout << "2. Dequeue word" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Enqueue sentence" << endl;
        cout << "5. Quit" << endl;
        getline(cin,x);
        if(x == "1"){
            cout << "word: ";
            string y;
            getline(cin,y);
            A.enqueue(y);
        }
        if(x == "2"){
            A.dequeue();
        }
        if(x == "3"){
            A.printQueue();
        }
        if(x == "4"){
            string l;
            string x;
            cout << "sentence: ";
            getline(cin,l);
            istringstream iss(l);

            while(iss >> x){
                A.enqueue(x);
            }
            }
    }
    cout << "Goodbye!" << endl;
}
