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
vector<int> adj[20];                   //adjacency list
int ans[20][20], path[20][20];         //parent of each node in its shortest path
int graph[20][20];                     //weight matrix

//Let's get started
int main(int argc, char *argv[]){

    int v,e,n1,n2,w;            //no of nodes and edges

    cout<<"Enter no of nodes and edges:";
    cin>>v>>e;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i == j) ans[i][j] = 0;
            else ans[i][j] = INT_MAX;   //initialize with distance = infinity
            path[i][j] = -1;            //initialize with -1 = no path
        }
    }

    cout<<"Node1 Node2 Weight:\n";
    for(int i=0; i<e; i++){
        cin>>n1>>n2>>w;
        adj[n1].push_back(n2);  //For undirected put vice-versa too
        ans[n1][n2] = w;
        path[n1][n2] = n1;
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
            cout<<ans[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
            cout<<path[i][j]<<"\t";
        cout<<endl;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            for(int k=0; k<v; k++){
                if(ans[i][k] == INT_MAX || ans[k][j] == INT_MAX) continue;
                if(ans[i][j] > ans[i][k] + ans[k][j]){
                    ans[i][j] = ans[i][k] + ans[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    //Now print the matrices
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
            cout<<ans[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
            cout<<path[i][j]<<"\t";
        cout<<endl;
    }

    return 0;
}
