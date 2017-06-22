/*  Code for breadth first traversal(BFS) and depth first search(DFS) in an undirected graph.
    The user has to input no of nodes and each edge. 1 3 says node 1 is connected to node 3
*/

#include <algorithm>
#include <iostream>
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
#include <set>
using namespace std;

vector<int> adj[20]; //adjacency list, considering maximum no of nodes to be 20
bool vis[20];   //array to check if a node is visited

void dfs(int x){
    vis[x] = true;
    cout<<x<<"\t";
    for(int i=0; i<adj[x].size(); i++){
        int v = adj[x][i];
        if(!vis[v])
            dfs(v);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()){
        v = q.front();
        cout<<v<<"\t";
        q.pop();
        for(int i=0; i<adj[v].size(); i++){
            if(!vis[ adj[v][i] ]){
                q.push(adj[v][i]);
                vis[adj[v][i]] = true;
            }
        }
    }
}

int main(){
    int n,m,a,b;
    cout<<"Enter the no of nodes and no of edges:";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); //For directed just remove this portion
    }
    cout<<"DFS:\t";
    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i);

    for(int i=0; i<n; i++) vis[i] = false;
    cout<<"\nBFS:\t";
    for(int i=0; i<n; i++)
        if(!vis[i])
            bfs(i);
    return 0;
}
