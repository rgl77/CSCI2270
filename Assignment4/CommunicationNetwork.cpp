#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork(){
    head = NULL;
    tail = NULL;

}

void CommunicationNetwork::printNetwork(){
    City *curr;
    curr = head;
    cout << "===CURRENT PATH===" << endl;
    while(curr != NULL){
            cout<<curr->cityName<< " -> ";
            curr = curr->next;
        }

    cout << " NULL"<< endl;
    cout << "==================" << endl;

}
void CommunicationNetwork::buildNetwork(){
    City* la = new City;
    la->cityName = "Los Angeles";

    City* ph = new City;
    ph->cityName = "Phoenix";

    City* de = new City;
    de->cityName = "Denver";

    City* da = new City;
    da->cityName = "Dallas";

    City* lo = new City;
    lo->cityName = "St. Louis";

    City* ch = new City;
    ch->cityName = "Chicago";

    City* atl = new City;
    atl->cityName = "Atlanta";

    City* dc = new City;
    dc->cityName = "Washington, D.C.";

    City* ny = new City;
    ny->cityName = "New York";

    City* bo = new City;
    bo->cityName ="Boston";



    la->next = ph;
    ph->next = de;
    de->next = da;
    da->next = lo;
    lo->next = ch;
    ch->next = atl;
   atl->next = dc;
    dc->next = ny;
    ny->next = bo;
    bo->next = NULL;
    head = la;
    tail = bo;

    printNetwork();


}



void CommunicationNetwork::transmitMsg(char* filename){
    ifstream file(filename);
    string word;
    City *curr;
    curr = head;
    if(head == NULL){
        cout	<<	"Empty	list"	<<	endl;
    } else {
        while(file >> word ){
            while(curr != NULL){
                curr->message = word;
                cout<<curr->cityName<<"	received	"<<curr->message<<endl;
                curr->message = "";
                curr = curr->next;
            }
            curr = head;

        }
    }
}

void CommunicationNetwork::addCity(string nam,string pre){

    if(pre == "First"){
        City* temp = new City;
        temp->cityName = nam;
        temp->next =head;
        head = temp;
        return ;
    }else{
        City*curr = head;
        City *temp = new City;
        while(curr!=NULL){
            if(curr->cityName == pre){
                temp->cityName = nam;

                temp->next = curr->next;
                curr->next = temp;
                break;
                }
              curr= curr->next;

            }
        }
}
    CommunicationNetwork::~CommunicationNetwork(){

    }



