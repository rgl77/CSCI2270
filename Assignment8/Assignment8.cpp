#include <iostream>
#include <fstream>
#include <sstream>
#include "movieTree.h"
using namespace std;

int main(int argc,char * argv[]){

    string x;
    MovieTree A;
    char *filename = argv[1];
    ifstream file(filename);
    string line,word,title;
    int ranking,year,quantity;
    while(getline(file,line)){
        stringstream ss(line);
        getline(ss,word,',');
        ranking = atoi(word.c_str());
        getline(ss,word,',');
        title = word;
        getline(ss,word,',');
        year = atoi(word.c_str());
        getline(ss,word,' ');
        quantity = atoi(word.c_str());
        A.addMovieNode(ranking,title,year,quantity);
    }



    while(x != "6"){
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        getline(cin, x);
        if(x== "1"){
            string p;
            cout << "Enter a title:" << endl;
            getline(cin,p);
            A.findMovie(p);
        }else if( x == "2"){
            string q;
            cout << "Enter a title:" << endl;
            getline(cin,q);
            A.rentMovie(q);
        }else if(x == "3"){
            A.printMovieInventory();
        }else if(x == "4"){
            string o;
            cout << "Enter a title:" << endl;
            getline(cin,o);
            A.deleteMovieNode(o);
        }else if(x == "5"){
            A.countMovieNodes();
        }
}

    A.~MovieTree();
    cout << "Goodbye!" << endl;


}
