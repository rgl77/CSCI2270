#include <iostream>
#include <fstream>
#include "movieTree.h"
using namespace std;

MovieNode* MovieTree::searchRecursive(MovieNode* node, string t){
    if(node == NULL){
        return node;
    }else{
        if(node->title == t){
            return node;
        }else if(node->title > t){
            return searchRecursive(node->leftChild, t);
        }else{
            return searchRecursive(node->rightChild, t);
        }
    }

}

MovieNode* MovieTree::search(string x){
    MovieNode* node = root;
    while(node!= NULL){
        if(node->title > x){
            node = node->leftChild;
        }else if(node->title < x){
            node = node->rightChild;
        }else{
            return node;
        }
    }
    return NULL;
}

MovieNode *MovieTree::treeMinimum(MovieNode *x){
    if(x == NULL){
        return NULL;
    }else{
    while(x->leftChild !=NULL){
        x = x->leftChild;
    }
    }
    return x;
}
void MovieTree::countMovieNodes(MovieNode *x, int *c){
   if(x == NULL){
        return;
    }
    else{
        *c += 1;
        if(x->leftChild != NULL){
            countMovieNodes(x->leftChild,c);
        }if(x->rightChild != NULL){
            countMovieNodes(x->rightChild,c);
        }

   }

}


void MovieTree::printMovieInventory(MovieNode *x){
    cout << "Movie:" << x->title << " " << x->quantity << endl;
    if(x->leftChild != NULL){
            printMovieInventory(x->leftChild);
    }if(x->rightChild != NULL){
            printMovieInventory(x->rightChild);
    }
}


void MovieTree::DeleteAll(MovieNode *x){
    if(x!= NULL){
        DeleteAll(x->leftChild);
        DeleteAll(x->rightChild);
        cout << "Deleting: " << x->title<< endl;
    }else{
        return;
    }

}

//Public Constructors


MovieTree::MovieTree(){
    root = NULL;
}
MovieTree::~MovieTree(){
    DeleteAll(root);
}

void MovieTree::printMovieInventory(){
    MovieNode*x = root;
    printMovieInventory(x);
}
int MovieTree::countMovieNodes(){
    MovieNode *x = root;
    //int *c;
    int counter = 0;
    //c = &counter;
    countMovieNodes(x,&counter);
    cout << "There are " << counter <<" movies in the list." << endl;
    return 0;
}

void MovieTree::addMovieNode(int x, string t, int y, int q){
    MovieNode *parent = NULL;
    MovieNode *temp   = root;
    MovieNode *node   = new MovieNode(x,t,y,q);
    while(temp != NULL){
        parent = temp;
        if( node->title < temp->title){
            temp = temp->leftChild;
        }else{
            temp = temp->rightChild;
        }
    }
    if(parent ==NULL){
        root = node;
    }else if(node->title < parent->title){
        parent->leftChild = node;
        node->parent = parent;
    }else{
        parent->rightChild = node;
        node->parent = parent;
    }
}
void MovieTree::findMovie(string x){
    MovieNode* node = search(x);
    if(node==NULL){
        cout << "Movie not found." << endl;
    }else{
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:"    << node->ranking << endl;
        cout << "Title:"      << node->title << endl;
        cout << "Year:"       << node->year << endl;
        cout << "Quantity:"   << node->quantity << endl;
    }

}

void MovieTree::rentMovie(string x){
    MovieNode* node = search(x);
    if(node == NULL) {
        cout << "Movie not found." << endl;
    }else{
        cout << "Movie has been rented." << endl;
        node->quantity = node->quantity - 1;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << node->ranking << endl;
        cout << "Title:" << node->title << endl;
        cout << "Year:" << node->year << endl;
        cout << "Quantity:" << node->quantity << endl;
        if(node->quantity == 0){
            deleteMovieNode(node->title);
        }
    }
}

void MovieTree::deleteMovieNode(string x){
    MovieNode* node = search(x);
    if(node == NULL){
        cout << "Movie not found." << endl;
    }else{
        if(node->leftChild == NULL && node->rightChild == NULL){
            if(node = node->parent->leftChild){
                node->parent->leftChild = NULL;
            }else if(node = node->parent->rightChild){
                node->parent->rightChild = NULL;
            }
        }else if(node->leftChild != NULL && node->rightChild != NULL){
            MovieNode *mini = treeMinimum(node->rightChild);
            if(mini == node->rightChild){
                node->parent->leftChild = mini;
                mini->parent = node->parent;
                mini->leftChild = node->leftChild;
                mini->leftChild->parent = mini;
            }else{
                mini->parent->leftChild = mini->rightChild;
                mini->rightChild->parent= mini->parent;
                mini->parent = node->parent;
                node->parent->leftChild = mini;
                mini->leftChild = node->leftChild;
                mini->rightChild= node->rightChild;
                node->rightChild->parent = mini;
                node->leftChild->parent = mini;
            }
        }else{
            if(node->parent->rightChild = node){
                if(node->leftChild){
                    MovieNode *k = node->leftChild;
                    node->parent->rightChild= k;
                    k->parent = node->parent;
                    delete node;
                }else{
                    MovieNode *p = node->rightChild;
                    node->parent->rightChild = p;
                    p->parent = node->parent;
                    delete node;
                }
            }else{
                if(node->leftChild){
                    MovieNode *q = node->leftChild;
                    node->parent->leftChild = q;
                    q->parent = node->parent;
                    delete node;
                }else{
                    MovieNode *w = node->rightChild;
                    node->parent->leftChild = w;
                    w->parent = node->parent;
                    delete node;
            }
        }

    }
  }
}
