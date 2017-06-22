/*
    Implementation of Belman ford algorithm for single source shortest path
    Here considering directed graphs.
    For V edges does V-1 iterations in which it considers all edges and relaxes them accordilngly.
    Fails in case of Negative weight cycle, ie a cycle exists for which net weight is negative.
    After V-1 iterations, do one more iteration, if any node gets mproved then there exists -ve weight cycle
    Run time: O(VE),    Space: O(V)
    Advantage over djikstra:  Djikstra fails in case of negative edges.
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
#include <utility>
using namespace std;

//Shortcuts
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair

//Globals
vector<int> adj[20];    //adjacency list
int parent[20];         //parent of each node in its shortest path
int graph[20][20], ans[20];

//Let's get started
int main(int argc, char *argv[]){

    int v,e,n1,n2,w;            //no of nodes and edges

    cout<<"Enter no of nodes and edges:";
    cin>>v>>e;
    for(int i=0; i<v; i++) ans[i] = INT_MAX;    //initializing distance of all nodes to be infinity
    cout<<"Node1 Node2 Weight:\n";
    for(int i=0; i<e; i++){
        cin>>n1>>n2>>w;
        adj[n1].push_back(n2);  //For undirected put vice-versa too
        graph[n1][n2] = w;
    }

    //Considering vertex 0 as source
    ans[0] = 0;

    for(int i=0; i<v-1; i++){
        for(int j=0; j<v; j++){     //considering each edge of each node, total E edges for all nodes
            for(int k=0; k<adj[j].size(); k++){
                n1 = j;
                n2 = adj[j][k];
                w = graph[n1][n2];
                if(ans[n1] + w < ans[n2]){
                    ans[n2] = ans[n1] + w;
                    parent[n2] = n1;
                }
            }
        }
    }

    //Now do one more iteration to check for -ve weight cycle
    bool cycle = 0;
    for(int j=0; j<v; j++){     //considering each edge of each node, total E edges for all nodes
        for(int k=0; k<adj[j].size(); k++){
            n1 = j;
            n2 = adj[j][k];
            w = graph[n1][n2];
            if(ans[n1] + w < ans[n2]){
                cycle = 1;
                cout<<"Negative weight cycle\n";
                exit(0);
            }
        }
    }

    //Now print distance along with parents
    for(int i=0; i<v; i++)
        cout<<"Node = "<<i<<",\tDistance = "<<ans[i]<<",\tParent = "<<parent[i]<<endl;


    return 0;
}
