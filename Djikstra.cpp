/*
    Implementation of Djikstras algorithm using adjacency list and min-heap(set)
    Running time: O(e lg (v));
    e = no of edges
    v = no of nodes
    Sample input:   Enter no of nodes and edges:9 14
                    Node1 Node2 Weight:
                    0 1 4
                    0 7 8
                    1 7 11
                    1 2 8
                    2 8 2
                    2 5 4
                    2 3 7
                    3 5 14
                    3 4 9
                    4 5 10
                    5 6 2
                    6 8 6
                    6 7 1
                    7 8 7
*/

#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <set>
using namespace std;

//considering 20 nodes
vector<int> adj[20];
int graph[20][20] = {0};              //graph[i,j] denotes weight of the edge between i and j, 0 means no edge
set< pair<int, int> > heap;     //heap for each node distance and node no, int_max means not yet included
int ans[20], path[20];

void printPath(int i){
    if(i==0) return;
    printPath(path[i]);
    cout<<path[i]<<",";
}

int main(){

    int v,e,n1,n2,w;            //no of nodes and edges
    pair<int, int> p;
    set< pair<int, int> > :: iterator it;

    cout<<"Enter no of nodes and edges:";
    cin>>v>>e;
    for(int i=0; i<v; i++) ans[i] = INT_MAX;    //initializing distance of all nodes to be infinity
    cout<<"Node1 Node2 Weight:\n";
    for(int i=0; i<e; i++){
        cin>>n1>>n2>>w;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        graph[n1][n2] = w;
        graph[n2][n1] = w;
    }

    //Considering vertex 0 as source
    ans[0] = 0;
    //Now insert all nodes with their vertices in the heap
    for(int i=0; i<v; i++){
        p = make_pair(ans[i], i);
        heap.insert(p);         //Vertices included will have a finite ans, not included will have int_max
    }

    //Start processing
    while(!heap.empty()){
        it = heap.begin();      //root of heap
        n1 = it->second;        //node with min ans
        p = *it;
        heap.erase(p);
        for(int i=0; i<adj[n1].size(); i++){
            n2 = adj[n1][i];    //2nd node
            if(ans[n1] != INT_MAX && ans[n2] > ans[n1] + graph[n1][n2]){
                p = make_pair(ans[n2], n2);   //remove old value
                heap.erase(p);
                ans[n2] = ans[n1] + graph[n1][n2];
                p = make_pair(ans[n2], n2);
                heap.insert(p);
                path[n2] = n1;
            }
        }
    }

    //printing the solution
    cout<<endl<<"Ditances from source:\n";
    for(int i=0; i<v; i++) {
        cout<<i<<":"<<ans[i]<<"->"<<path[i];
        printPath(path[i]);
        cout<<path[i]<<","<<endl;
    }

    for(int i=0; i<v; i++) cout<<i<<":"<<path[i]<<endl;

    return 0;
}
