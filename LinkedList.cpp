#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
	Node *previous;
	Node(int k, Node *n, Node *p){
		key = k;
		next = n;
		previous = p;
	}
};

class LinkedList{
	private:
		Node *head;
		Node *search(int value){

		}

	public:

		LinkedList(){head = NULL;};

		void getName()
		   {
			cout<<"Enter your Name Here...";
		   }

		void addNode(int value, int newVal){
			if(head == NULL){
                head = new Node(newVal, NULL, NULL);
               // tail = head;
                return;
			}
			Node *temp = head;
			bool found  = false;
			while(temp){
                if(temp->key == value){
                    found = true;
                    break;
                }
                temp = temp->next;
			}
			if(found == true){
                Node *x= new Node(newVal,temp->next,temp);
                temp->next = x;

			}else{
                Node *p = new Node(newVal, head, NULL);
                head = p;
			}
}
   Node *getHead()
      {
		return head;
      }
		void printList(){
			Node *x = head;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}
};
