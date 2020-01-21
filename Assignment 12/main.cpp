#include "graph.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>
int main(int argc,char* argv[]){
    string city,line,word,fromCity,toCity,user;
    int index = 0,distance;
    Graph<string> A;
    char *filename = argv[1];
    ifstream file(filename);
    vector<string> cities;
    while(getline(file,line)){
        stringstream ss(line);
        getline(ss,word,',');
        if(word == "cities"){
            while(getline(ss,word,',')){
                cities.push_back(word);
                for(int i = 0;i < cities.size();i++){
                    A.addVertex(cities[i]);
                }
            }
            continue;
        }
        fromCity = word;
        index = 0;
        while(getline(ss,word,',')){

            toCity = cities[index];
            distance = stoi(word.c_str());
            if(distance > 0){
            A.addEdge(fromCity,toCity,distance);
            }
            index++;
        }
    }
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
