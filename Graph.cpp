#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.visited = false;
        v.district = -1;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<< vertices[i].district <<":"
        <<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}

void Graph::findDistricts(){
    int V = vertices.size();
    int counter = 1;
    for(int a=0; a<V; a++){
        if(vertices[a].visited == false){
            vertex first = vertices[a];
            std::vector<vertex> Queue;
            Queue.push_back(first);
        //cout<<first.name<<endl;

        while(Queue.size() > 0){
            vertex temp;
            temp = Queue[0];
            Queue.pop_back();
            int length = temp.adj.size();
            int currentposition = -1;

            for(int k=0; k<V; k++){
                if(vertices[k].name == temp.name){
                    currentposition = k;
                }
            }

            for(int j=0; j<length; j++){

            if(vertices[currentposition].adj[j].v->visited == false){
                vertices[currentposition].adj[j].v->visited = true;
                vertices[currentposition].adj[j].v->district = counter;
                //cout<<vertices[currentposition].adj[j].v->name<<endl;
                vertex temp2 = *vertices[currentposition].adj[j].v;
                Queue.push_back(temp2);
            }
            }
        }
            counter++;

        }
    }
}

queueVertex Graph::findShortestPath(string city1,string city2){
    vertex V1, V2;
    int city1Position, city2Position;
    for(int b=0; b<vertices.size(); b++){
        vertices[b].visited = false;
        if(vertices[b].name == city1){
            V1 = vertices[b];
            city1Position = b;
        }
        if(vertices[b].name == city2){
            V2 = vertices[b];
            city2Position = b;
        }
    }

    if(V1.name != city1 or V2.name != city2){
        cout << "One or more cities doesn't exist" << endl;
    }
    else if(V1.district != V2.district){
        cout << "No safe path between cities" << endl;
    }
    else{
        int position;
        std::vector<vertex> path;
        int tempDistance;
        vertices[city1Position].visited = true;
        queueVertex qv;
        qv.distance = 1;
        qv.path = {vertices[city1Position]};
        std::vector<queueVertex> Queue2; //Empty Queue
        Queue2.push_back(qv);

        while(Queue2.size() > 0){

            qv = Queue2[0];
            Queue2.pop_back();
            int length = qv.path.size();
            vertex Last = qv.path[length-1];
             for(int k=0; k<vertices.size(); k++){
                if(vertices[k].name == Last.name){
                    position = k;
                }
            }

            length = Last.adj.size();
            for(int c = 0; c < length; c++){
                if(vertices[position].adj[c].v->visited == false){


                    path = qv.path;
                    vertices[position].adj[c].v->visited = true;
                    tempDistance = qv.distance + 1;
                    path.push_back(*vertices[position].adj[c].v);


                    queueVertex temp;
                    temp.path = path;
                    temp.distance = tempDistance;
                    if(vertices[position].adj[c].v->name == city2){
                        return temp;
                    }
                    else{
                        Queue2.push_back(temp);
                    }

                }
            }


        }
    }
    queueVertex doba;
    doba.distance = 0;
    return doba;
}

string Graph::returnVertexName(int index){
    string name;
    name = vertices[index].name;

    return name;
}

void Graph::findShortestDistance(std::string sourceVertex, std::string destinationVertex){
    int sourcePosition, destinationPosition;
    int distanceTotal = 0;
    int currentMin;
    int currentPosition;
    for(int i=0; i<vertices.size(); i++){
        if(sourceVertex==vertices[i].name){
            sourcePosition = i;
        }
        if(destinationVertex==vertices[i].name){
            destinationPosition = i;
        }
        vertices[i].visited = false;
        vertices[i].distance = 100000000000000000000000000;
    }
    vertices[sourcePosition].visited = true;
    vertices[sourcePosition].distance = 0;
    std::vector<vertex> Queue3;
    std::vector<vertex> FinalQueue;
    Queue3.push_back(vertices[sourcePosition]);
    FinalQueue.push_back(vertices[sourcePosition]);
    vertex temporary;
    while(vertices[destinationPosition].visited == false){

        currentMin = 10000000000000000000000000000000;
        //for(int j=0; j<Queue3.size(); j++){
            temporary = Queue3[0];
            for(int k=0; k<vertices.size(); k++){
                if(vertices[k].name == temporary.name){
                    currentPosition = k;
                }
            }
            //cout<<"kush"<<endl;
            for(int a=0; a<vertices[currentPosition].adj.size(); a++){
                if(vertices[currentPosition].adj[a].v->visited == false && vertices[currentPosition].adj[a].weight < currentMin){
                    currentMin = vertices[currentPosition].adj[a].weight;
                    temporary = *vertices[currentPosition].adj[a].v;
                    cout<<"pass"<<endl;
                }
            }
            //cout<<temporary.name<<endl;
        for(int i=0; i<vertices.size();i++){
            if(vertices[i].name == temporary.name){
                vertices[i].visited = true;
            }
        }
        Queue3.pop_back();
        Queue3.push_back(temporary);
        FinalQueue.push_back(temporary);
        distanceTotal = distanceTotal + currentMin;
        }
    }





