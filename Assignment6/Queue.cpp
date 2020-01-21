#include <iostream>
#include <fstream>
#include "Queue.h"
using namespace std;
Queue::Queue(int key){
    queueSize = key;
    arrayQueue= new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}
Queue::~Queue(){}
bool Queue::queueIsFull(){
    bool result = true;
    if(queueCount == queueSize){
        result = true;

    }else{
        result = false;
    }
    return result;
}

bool Queue::queueIsEmpty(){
    if(queueCount == 0){
        return true;
    }else{
        return false;
    }
}

void Queue::printQueue(){
    if(queueIsEmpty() != true){
    int i = 0;
    int j = queueHead;
    while(i < queueCount){
        if(j == queueSize){
            j = 0;
        }

        cout << j << ": " << arrayQueue[j] << endl;
        i++;
        j++;
}
    }else{
        cout << "Empty" << endl;
    }
}
void Queue::enqueue(string val){
    if(queueIsFull() != true){
        arrayQueue[queueTail] = val;
        queueCount++;

        if(queueTail == queueSize - 1){
            queueTail = 0;
        }else{
            queueTail++;
        }

        cout << "E: " << val << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    }else{
        cout <<"Queue is full." << endl;
    }
}

string Queue::dequeue(){
    string value;
    if(queueIsEmpty() != true){
         value = arrayQueue[queueHead];
         queueCount--;

        if(queueHead == queueSize - 1){
            queueHead = 0;
        }else{
            queueHead++;
        }
        cout << "H: " << queueHead << endl;
         cout << "T: " << queueTail << endl;
         cout << "word: " << value << endl;
    }else{
        cout << "Queue is empty." << endl;
    }
    return value;


}

