#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

template<class T>
Graph<T>::Graph(){
}


template<class T>
Graph<T>::~Graph(){}

template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight){
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i].name == v1){
                for(int j = 0; j<vertices.size(); j++){
                    if(vertices[j].name == v2 && i != j){
                        adjVertex<T> av;
                        av.v = &vertices[j];
                        av.weight = weight;
                        vertices[i].adj.push_back(av);
                    }
                }
            }
        }
    }


template<class T>
void Graph<T>::addVertex(T n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            break;
        }
    }
    if(found == false){
        vertex<T> v;
        v.name = n;
        vertices.push_back(v);
    }
}

template<class T>
void Graph<T>::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i].district << ": "<< vertices[i].name << "->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << "**";
        }
        cout << endl;
    }

}

template<class T>
vertex<T> * Graph<T>::findVertex(T name){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
}

template<class T>
void Graph<T>::BFTraversalLabel(T start, int id){
    vertex<T>* p = findVertex(start);
    vertex<T> *n;
    p->visited = true;
    queue<vertex<T>*> q;
    q.push(p);
    while(q.size()!= 0){
        n = q.front();
        q.pop();
        n->district = id;
        for(int x = 0; x < n->adj.size(); x++){
            if(!n->adj[x].v->visited){
                n->adj[x].v->visited = true;
                n->adj[x].v->district = id;
                q.push(n->adj[x].v);
            }
        }
    }
}

template<class T>
void Graph<T>::assignDistricts(){
    int id = 1;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].district < 0){
            BFTraversalLabel(vertices[i].name,id);
            id++;
        }
        //id++;
    }
}

template<class T>
void Graph<T>::shortestPath(T start,T ending){
    vertex<T> *startV = findVertex(start);
    vertex<T> *endV   = findVertex(ending);
    startV->visited = true;
    startV->distance = 0;
    queue<vertex<T>*> solved;
    solved.push(startV);
    int min_dist,dist;
    vertex<T> *solvedV;
    vertex<T> *s;
    vertex<T> *parent;
    while(endV->visited != true){
        min_dist = INT_MAX;
        solvedV = NULL;
        for(int x = 0; x< solved.size();x++){
            s = solved.front();
            solved.pop();
            for(int y = 0; y < s->adj.size(); y++){
                if(s->adj[y].v->visited != true){
                    dist = s->distance + s->adj[y].weight;
                    if(dist < min_dist){
                        solvedV = s->adj[y].v;
                        min_dist = dist;
                        parent = s;
                    }
                }
            }
        }
        solvedV->distance = min_dist;
        solvedV->parent = parent;
        solvedV->visited = true;
        solved.push(solvedV);

    }
    cout << min_dist << endl;
}
