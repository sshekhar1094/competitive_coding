/*
    Implementation for Kruskals algorithm for minimum spanning tree. The algo starts picking the minimum weight edges and
    includes that edge in the MST unless that edge forms any cycle. Disjoint sets are used to check for cycles. If 2 nodes
    have the same parents then they form a cycle

    Sample input:
            Nodes and edges = 9, 14
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
            6 5 2
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
#include <utility>
using namespace std;

//Shortcuts
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define mp make_pair

//Globals
pair<int, pair<int, int> > p[1000];  //pair<weight, <node1, node2> >
int root[1000];

//Let's get started
void initialize(int n){
    for(int i=0; i<n; i++)
        root[i] = i;
}

int parent(int n){
    while(root[n] != n)
        n = root[n];
    return n;
}

void unify(int x, int y){
    int p = parent(x);
    int q = parent(y);
    root[p] = q;
}

int kruskal(int nodes, int edges){
    int x,y,wt, ans=0;
    for(int i=0; i<edges; i++){
        x = p[i].second.first;      //1st node
        y = p[i].second.second;     //2nd node
        wt = p[i].first;            //weight
        if(parent(x) != parent(y)){ //not form a cycle
            unify(x, y);
            ans = ans + wt;
        }
    }
    return ans;
}

int main(int argc, char *argv[]){
    int nodes, edges, wt, x, y;
    cout<<"Enter no of nodes and no of edges:";
    cin>>nodes>>edges;
    initialize(nodes);
    cout<<"Enter nod1, nod2, weight:\n";
    for(int i=0; i<edges; i++){
        cin>>x>>y>>wt;
        p[i] = mp(wt, mp(x,y));
    }
    sort(p, p+edges);   //sorting so that min wt edges come first
    int minWt = kruskal(nodes, edges);
    cout<<"Weight of MST is "<<minWt;
    return 0;
}
