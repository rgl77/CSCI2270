#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
using namespace std;

CommunicationNetwork::CommunicationNetwork(){
    head = NULL;
    tail = NULL;
}
void CommunicationNetwork::printNetwork(){
    if(head==NULL){
        cout << "===CURRENT PATH===" << endl;
        cout << "NULL" << endl;
        cout << "==================" << endl;

    }else{
    City *curr;
    curr = head;
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL <- " ;
    while(curr->next != NULL){
        cout << curr->cityName << " <-> ";
        curr = curr->next;
    }
    cout << curr->cityName << " -> " << "NULL" << endl;
    cout << "==================" << endl;
}
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

    bo->previous = ny;
    ny->previous = dc;
    dc->previous = atl;
   atl->previous = ch;
    ch->previous = lo;
    lo->previous = da;
    da->previous = de;
    de->previous = ph;
    ph->previous = la;
    la->previous = NULL;

    printNetwork();
}

void CommunicationNetwork::transmitMsg(char* filename){
    ifstream file(filename);
    string word;
    City *curr;

    if(head == NULL){
        cout<< "Empty list" << endl;
    }else{
        while(file>>word){
            curr = head;
            while(curr != NULL){
                curr->message = word;
                cout<< curr->cityName <<" received " << curr->message << endl;
                curr->message ="";
                curr = curr->next;
            }
                curr = tail->previous;
            while(curr != NULL){
                curr->message = word;
                cout<< curr->cityName << " received " << curr->message<<endl;
                curr->message="";
                curr = curr->previous;
            }
        }
    }
}

void CommunicationNetwork::addCity(string nam, string prev){
    if(head == NULL){
        head = new City(nam, NULL, NULL, "");
        tail = head;
        return;
        }

   City* temp = head;
   bool found = false;
   if(prev == "First"){
    City *temp1 = new City(nam,head,NULL,"");
    head = temp1;
    return;
   }

   while(temp){
    if(temp->cityName == prev){
        found = true;
        break;
        }
    temp = temp -> next;
    }

    if(found == true){
        City *newc = new City(nam,temp->next,temp,"");
        temp->next = newc;
        tail = newc;
    }else{
        cout <<" City not found" << endl;
         }

}
CommunicationNetwork::~CommunicationNetwork(){

}

void CommunicationNetwork::deleteCity(string nam){
    City *curr = head;
    City *temp;
    if(head->cityName == nam){
        temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;


    }else{
        while(curr){
            if(curr->cityName == tail->cityName){

                tail=tail->previous;
                tail->next=NULL;
                delete curr;
                return;
            }
            if(curr->cityName == nam){
            curr->previous->next=curr->next;
            curr->next->previous=curr->previous;
            delete curr;
            return;
            }
            curr = curr->next;
        }
        if(curr->cityName != nam){
            cout << nam <<"not found"<<endl;
        }

    }

}

void CommunicationNetwork::deleteNetwork(){



    while(head!=NULL){
        City*curr=head;
        cout <<"deleting " << head->cityName << endl;
        head = head->next;
        delete curr;

    }
}

