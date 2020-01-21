#include <iostream>
#include "movieTree.h"
using namespace std;

//Private constructors
void MovieTree::DeleteAll(MovieNode *node){
    if(node != nil){
        DeleteAll(node->leftChild);
        DeleteAll(node->rightChild);
        cout << "Deleting :" << node->title << endl;
    }else{
        return;
    }
}

void MovieTree::printMovieInventory(MovieNode * node){

    //cout << "Movie :" << node->title << " " << node->quantity << endl;
    if(node->leftChild != nil){
        printMovieInventory(node->leftChild);
    }
    cout << "Movie :" << node->title << " " << node->quantity << endl;
    if(node->rightChild != nil){
        printMovieInventory(node->rightChild);
    }
}



void MovieTree::rbAddFixup(MovieNode *x){
    while(x!= root && x->parent->isRed == true){
      if(x->parent == x->parent->parent->leftChild){
        MovieNode* uncle = x->parent->parent->rightChild;
        if(uncle->isRed == true){
            x->parent->isRed = false;
            uncle->isRed     = false;
            x->parent->parent->isRed = true;
            x = x->parent->parent;
        }else{
            if(x == x->parent->rightChild){
                x = x->parent;
                leftRotate(x);
            }
            x->parent->isRed = false;
            x->parent->parent->isRed = true;
            rightRotate(x->parent->parent);

        }
      }else{
        MovieNode* uncle = x->parent->parent->leftChild;
        if(uncle->isRed == true){
            x->parent->isRed = false;
            uncle->isRed     = false;
            x->parent->parent->isRed = true;
            x = x->parent->parent;
        }else{
            if(x == x->parent->leftChild){
                x = x->parent;
                rightRotate(x);
            }
            x->parent->isRed = false;
            x->parent->parent->isRed = true;
            leftRotate(x->parent->parent);

        }
      }
   }
   root->isRed = false;
}

void MovieTree::leftRotate(MovieNode* node){
    MovieNode* y = node->rightChild;
    node->rightChild = y->leftChild;
    if(y->leftChild != nil){
        y->leftChild->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == nil){
        root = y;
    }else{
        if(node == node->parent->leftChild){
            node->parent->leftChild = y;
        }else{
            node->parent->rightChild = y;
        }
    }
    y->leftChild = node;
    node->parent = y;
}

void MovieTree::rightRotate(MovieNode *node){
    MovieNode* x = node->leftChild;
    node->leftChild = x->rightChild;
    if(x->rightChild != nil){
        x->rightChild->parent = node;
    }
    x->parent = node->parent;
    if(node->parent == nil){
        root = x;
    }else if(node == node->parent->rightChild){
        node->parent->leftChild = x;
    }else{
        node->parent->rightChild = x;
    }
    x->rightChild = node;
    node->parent = x;
}

void MovieTree::rbDeleteFixup(MovieNode* x){
    MovieNode* s;
    while (x != root && x->isRed == false){
        if(x == x->parent->leftChild){
            s = x->parent->rightChild;
            if(s->isRed == true){
                s->isRed = false;
                x->parent->isRed = true;
                leftRotate(x->parent);
                s = x->parent->rightChild;
            }
            if(s->leftChild->isRed == false && s->rightChild->isRed == false){
                s->isRed = true;
                x = x->parent;
            }
            else if(s->leftChild->isRed == true && s->rightChild->isRed == false){
                s->leftChild->isRed = false;
                s->isRed = true;
                rightRotate(s);
                s = x->parent->rightChild;
            }
            else{
                s->isRed = x->parent->isRed;
                x->parent->isRed = false;
                s->rightChild->isRed = false;
                leftRotate(x->parent);
                x = root;
            }
        }else{
                  s=x->parent->leftChild;
                  if(s->isRed== true)
                  {
                        s->isRed=false;
                        x->parent->isRed=true;
                        rightRotate(x->parent);
                        s=x->parent->leftChild;
                  }
                  if(s->leftChild->isRed==false &&s->rightChild->isRed==false)
                  {
                        s->isRed=true;
                        x=x->parent;
                  }
                  else
                  {
                        if(s->leftChild->isRed== false)
                        {
                              s->rightChild->isRed=false;
                              s->isRed=true;
                              leftRotate(s);
                              s=x->parent->leftChild;
                        }
                        s->isRed=x->parent->isRed;
                        x->parent->isRed=false;
                        s->leftChild->isRed=false;
                        rightRotate(x->parent);
                        x=root;
                  }
          }
       x->isRed=false;
       root->isRed=false;
    }
}

int MovieTree::rbValid(MovieNode * node)
{
        int lh = 0;
        int rh = 0;

        // If we are at a nil node just return 1
        if (node == nil)
            return 1;

        else
        {
            // First check for consecutive red links.
            if (node->isRed)
            {
                if(node->leftChild->isRed || node->rightChild->isRed)
                {
                    cout << "This tree contains a red violation" << endl;
                    return 0;
                }
            }

            // Check for valid binary search tree.
            if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0))
            {
            cout << "This tree contains a binary tree violation" << endl;
            return 0;
        }

        // Deteremine the height of let and right children.
        lh = rbValid(node->leftChild);
        rh = rbValid(node->rightChild);

        // black height mismatch
        if (lh != 0 && rh != 0 && lh != rh)
        {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }

        // If neither height is zero, incrament if it if black.
        if (lh != 0 && rh != 0)
        {
                if (node->isRed)
                    return lh;
                else
                    return lh+1;
        }

        else
            return 0;

    }
}

/*int MovieTree::countMovieNodes(MovieNode *node){
    if(node == NULL){
        return 0;
    }else if(!node->leftChild && !node->rightChild){
        return 1;
    }else{
       if(node->leftChild != NULL){
        countMovieNodes(node->leftChild);
       }if(node->rightChild != NULL){
        countMovieNodes(node->rightChild);
       }
    }

}*/

int MovieTree::countMovieNodes(MovieNode* node){
    if(node == NULL){
        return 0;
    }
    if(node->leftChild == nil && node->rightChild == nil){
        return 1;
    } else{
        return countMovieNodes(node->leftChild) + countMovieNodes(node->rightChild);
    }
}

int MovieTree::countLongestPath(MovieNode * node){
    if(node == NULL){
        return 0;
    }else{
        int lheight = countLongestPath(node->leftChild);
        int rheight = countLongestPath(node->rightChild);
        if(lheight > rheight){
            return lheight+1;
        }else{
            return rheight+1;
        }
    }
}

MovieNode * MovieTree::searchMovieTree(MovieNode *node, string title){
    if(node == nil){
        cout << "There is no movie that you named. " << endl;
        return node;
    }else{
        if(node->title == title){
            return node;
        }else if(node->title > title){
            return searchMovieTree(node->leftChild, title);
        }else{
            return searchMovieTree(node->rightChild, title);
        }
    }
}

void MovieTree::rbDelete(MovieNode* node){
    bool NodeColor = node->isRed;
    MovieNode* x ;
    if(node!=root){
        if(node->leftChild == nil && node->rightChild == nil){
            if(node->parent->leftChild = node){
                node->parent->leftChild = nil;
                x = node->parent->leftChild;
            }else{
                node->parent->rightChild = nil;
                x = node->parent->rightChild;
            }
        }else if(node->leftChild != nil && node->rightChild != nil){
            MovieNode* mini;
            MovieNode* temp = node->rightChild;
            if(temp == nil){
                mini = nil;
            }else{
                while(temp->leftChild != nil){
                    temp = temp->leftChild;
                }
                mini = temp;
            }
            NodeColor = mini->isRed;
            x = mini->rightChild;
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
                node->rightChild->parent= mini;
                node->leftChild->parent = mini;
                //mini->isRed = node->isRed;
            }
            mini->isRed = node->isRed;
        }else{
            x = node->leftChild;
            node->parent->leftChild = x;
            x->parent = node->parent;
        }
    }else{
}

}
void MovieTree::rbTransplant(MovieNode* node, MovieNode *x){
}

MovieTree::MovieTree(){
    nil = new MovieNode(0,"",0,-1);
    nil->isRed = false;
    root = nil;
}

MovieTree::~MovieTree(){
    DeleteAll(root);
}
void MovieTree::printMovieInventory(){
    if(root == NULL){
        cout << "Tree is empty." << endl;
    }else{
        printMovieInventory(root);
    }
}
int MovieTree::countMovieNodes(){
    if(root == NULL){
        cout << "Tree is empty" << endl;
    }else{
    cout << "The number of nodes: " << countMovieNodes(root) << endl;
    }
}
void MovieTree::deleteMovieNode(string x){
    MovieNode* node = searchMovieTree(root, x);
    rbDelete(node);
}
/*void MovieTree::addMovieNode(int ranking, string title, int year, int quantity){
    MovieNode* node = new MovieNode(ranking,title,year,quantity);
    //node->parent = nil;
    node->leftChild = nil;
    node->rightChild= nil;
    node->parent    = nil;
    node->isRed     = true;
    MovieNode* temp = root;
    MovieNode*parent= nil;
    if(root == NULL){
        root = node;
        rbAddFixup(root);
        return;
    }else{
       while(temp!=nil){
            parent = temp;
            if(node->title.compare(temp->title) < 0){
                temp = temp->leftChild;
            }else{
                temp = temp->rightChild;
            }
        }
        //node->parent = parent;
        if(parent == nil){
            root = node;
        }
        else if(node->title.compare(parent->title) < 0){
            parent->leftChild = node;
        }else{
            parent->rightChild= node;
        }
       rbAddFixup(node);
        return;
    }
}
*/
void MovieTree::findMovie(string x){
    MovieNode *node;
    node = searchMovieTree(root,x);
    //cout << "Movie found" << endl;
}
void MovieTree::rentMovie(string x){
    MovieNode* node = searchMovieTree(root, x);
    if(node == nil || node == NULL){
        cout << "Movie not found. " << endl;
    }else if(node != nil && node != NULL){
        cout << "Movie has been rented." << endl;
        node->quantity = node->quantity - 1;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << node->ranking << endl;
        cout << "Title:" << node->title << endl;
        cout << "Year:" << node->year << endl;
        cout << "Quantity:" << node->quantity << endl;
        if(node->quantity == 0){
            deleteMovieNode(x);
        }

    }
}
bool MovieTree::isValid(){
    int c = MovieTree::rbValid(root);
    if(c == 0){
        return false;
    }else{
        return true;
    }
}
int MovieTree::countLongestPath(){
    cout << "The height of the tree is :" << countLongestPath(root) << endl;
    return 0;
}

void MovieTree::addMovieNode(int ranking, string title, int year, int quantity){
    MovieNode* node = new MovieNode(ranking,title,year,quantity);
    node->leftChild = nil;
    node->rightChild= nil;
    node->isRed     = true;
    MovieNode *temp = root;
    MovieNode *parent=nil;
    while(temp!=nil){
        parent = temp;
        if(node->title < temp->title){
            temp = temp->leftChild;
        }else{
            temp = temp->rightChild;
        }
    }
    if(parent == nil){
        root = node;
    }else if(node->title < temp->title){
        parent->leftChild = node;
    }else{
        parent->rightChild= node;
    }
    node->parent = parent;
    rbAddFixup(node);
}



