// Orgil Sugar
// Thursday 8 AM recitation
// Rhonda Hoenigman Aayush Grover

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Product{                // struct
    string type;
    string av;
    string price;

};
int main(){
    Product x[100];                                 //declaring an array
    ifstream inFile;
    string line;
    string filename;                                // filename from the user
    int lines = 1;                                  // line number
    int i = 0;                                      // array element
    cout << "Please enter the file name" << endl;
    cin  >> filename;

    inFile.open(filename.c_str());                   // opening file
    if(inFile.is_open()){
        while((getline(inFile,line,'\n')&&(i < 100)))  // reading file if file is open
        {
           stringstream ss(line);                      // separating lines by using ss
           ss >> x[i].type ;
           ss >> x[i].av ;

            if(x[i].av == "forsale,"){
                cout <<x[i].type << ", for sale, " << x[i].price << endl;
            }
            if(x[i].av == "forwanted,"){
                cout << x[i].type << ", for wanted, " << x[i].price << endl;
            }
           ss >> x[i].price ;

            lines ++;
            i++;
        }

    }
    else{
        cout << "Opened unsuccessfully" << endl;                            //checking file is open or not
    }
}
