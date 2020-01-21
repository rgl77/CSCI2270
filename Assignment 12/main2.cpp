#include "graph.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]){
    string name,word,city1,line;
    Graph<string> A;
    char* filename = argv[1];
    ifstream file(filename);
    int distance;
    getline(file,line);
    stringstream ss(line);
    getline(ss,name,',');
    while(getline(ss,name,',')){
        A.addVertex(name);
    }

    string atl="Atlanta",bos="Boston",bou="Boulder",che="Cheyenne",chi="Chicago",cle="Cleveland",dis="Disneyland";
    string key="Key West",mia="Miami",newo="New Orleans",ny="New York",port="Portland",sanf="San Francisco",seat="Seattle",yak="Yakima";
    int counter = 1;
    while(getline(file,line)){
        stringstream s1(line);
        getline(ss,word,',');
        city1 = word;
        while(getline(ss,word,',')){
            distance = atoi(word.c_str());
            if(distance=!0 && distance != -1){
                if(counter % 15 == 1){
                   A.addEdge(city1,atl,distance);
                }
                if(counter % 15 == 2){
                    A.addEdge(city1,bos,distance);
                }
                if(counter % 15 == 3){
                    A.addEdge(city1,bou,distance);
                }
                if(counter % 15 == 4){
                    A.addEdge(city1,che,distance);
                }
                if(counter % 15 == 5){
                    A.addEdge(city1,chi,distance);
                }
                if(counter % 15 == 6){
                    A.addEdge(city1,cle,distance);
                }
                if(counter % 15 == 7){
                    A.addEdge(city1,dis,distance);
                }
                if(counter % 15 == 8){
                    A.addEdge(city1,key,distance);
                }
                if(counter % 15 == 9){
                    A.addEdge(city1,mia,distance);
                }
                if(counter % 15 == 10){
                    A.addEdge(city1,newo,distance);
                }
                if(counter % 15 == 11){
                    A.addEdge(city1,ny,distance);
                }
                if(counter % 15 == 12){
                    A.addEdge(city1,port,distance);

                if(counter % 15 == 13){
                    A.addEdge(city1,sanf,distance);
                }
                if(counter % 15 == 14){
                    A.addEdge(city1,seat,distance);
                }
                if(counter % 15 == 0){
                    A.addEdge(city1,yak,distance);
                }
            }
            counter++;
        }
      }
    }
    string user;
    while(user != "4"){
        cout << "======Main Menu======" << endl;
        cout <<"1. Print vertices" << endl;
        cout <<"2. Find districts" << endl;
        cout <<"3. Find shortest path" << endl;
        cout <<"4. Quit" << endl;
        getline(cin,user);
        if(user == "1"){
            A.displayEdges();
        }
        if(user == "2"){
            A.assignDistricts();
        }
        if(user == "3"){
            string city2,city3;
            getline(cin,city2);
            getline(cin,city3);
            A.shortestPath(city2,city3);
        }
    }


}
