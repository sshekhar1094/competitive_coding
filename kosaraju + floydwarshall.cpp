//Implementing Kosaraju's Algorithm for finding strongly connected components
//Then FloydWarshall Algorithm for finding longest shortest path (diameter) of SSC

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
#include <stack>
using namespace std;

vector<int> adj[1090], adjRev[1090];		//adjacency list for nodes
bool vis[1090];
vector<int> ssc[1090];		//for strongly connected components
double graph[1090][1090] = {0.0};
stack<int> st;	
double ans[1090][1090];		//shortest distance between each pairs

void dfs(int x){
	vis[x] = true;
    //cout<<x<<"\t";
    for(int i=0; i<adj[x].size(); i++){
        int v = adj[x][i];
        if(!vis[v])
            dfs(v);
    }
    st.push(x);
}

void dfs2(int x, int sz){
	vis[x] = true;
	//cout<<x<<",";
	ssc[sz].push_back(x);
    for(int i=0; i<adjRev[x].size(); i++){
        int v = adjRev[x][i];
        if(!vis[v])
            dfs2(v, sz);
    }
    
}

void findDia(int ind){		//ind is the index of largest ssc
	int nodes = ssc[ind].size();	//No od nodes in ssc
	int a, b, c;
	for(int i=0; i<nodes; i++){
		a = ssc[ind][i];
		for(int j=0; j<nodes; j++){
			b = ssc[ind][j];
			if(i == j) ans[a][b] = 0;
			else if(graph[a][b] != 0.0) ans[a][b] = graph[a][b];
			else ans[a][b] = INT_MAX;
		}
	}

	for(int i=0; i<nodes; i++){
		for(int j=0; j<nodes; j++){
			for(int k=0; k<nodes; k++){
				a = ssc[ind][i];
				b = ssc[ind][j];
				c = ssc[ind][k];
				if(ans[i][k] == INT_MAX || ans[k][j] == INT_MAX) continue;
				if(ans[i][j] > ans[i][k] + ans[k][j])
                    ans[i][j] = ans[i][k] + ans[k][j];
			}
		}
	}

	//Print distances
	double mx = -1;
	for(int i=0; i<nodes; i++)
		for(int j=0; j<nodes; j++){
			a = ssc[ind][i];
			b = ssc[ind][j];
			//cout<<a<<":"<<b<<":"<<ans[a][b]<<endl;
			if(ans[a][b] > mx)
				mx = ans[a][b];
		}


	cout<<endl<<"The Diameter of SSC is "<<mx<<endl;

}

int main(){
	int a,b,tmp; 	//nodes
	double wt;	//wt of node
	int nodes, edges;	//no of nodes and edges

	//Taking input
	scanf("%d %d %d", &nodes, &tmp, &edges);

	for(int i=0; i<edges; i++){
		scanf("%d %d", &a, &b);
		cin>>wt;
		graph[a][b] = wt;
		adj[a].push_back(b);
		adjRev[b].push_back(a);		//for reverse graph
		//cout<<a<<" "<<b<<" "<<graph[a][b]<<endl;
	}

	/*for(int i=0; i<=nodes; i++){
		cout<<i<<":";
		for(int j=0; j<adj[i].size(); j++)
			cout<<adj[i][j];
		cout<<endl;
	}*/

	//Now starting dfs traversal

	for(int i=0; i<nodes; i++)
        if(!vis[i])
            dfs(i);
    for(int i=0; i<=nodes; i++) vis[i] = false;
	vis[1074] = 1;

    //Printing order of stack
	/*while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;*/

	/*for(int i=0; i<nodes; i++){
		cout<<i<<":";
		for(int j=0; j<adjRev[i].size(); j++)
			cout<<adjRev[i][j];
		cout<<endl;
	}*/

	//Now finding the SCC's
	int tp, sz=0;
	while(!st.empty()){
		tp = st.top();
		st.pop();
		if(!vis[tp]){
			//cout<<endl<<"Strongly connected:";
			dfs2(tp, sz);
			sz++;
		}
	}

	//Printing SSC's
	/*for(int i=0; i<sz; i++){		//sz will be no of ssc's
		cout<<endl<<i+1<<":";
		for(int j=0; j<ssc[i].size(); j++)
			cout<<ssc[i][j]<<",";
	}
	cout<<endl;*/

	//Now finding largest SSC
	int ind, mx = -1, size;
	for(int i=0; i<sz; i++){
		//cout<<i<<":"<<ssc[i].size()<<":"<<mx<<":"<<(ssc[i].size() > mx)<<endl;
		size = ssc[i].size();
		if(size > mx){
			//cout<<"\t"<<i<<":"<<ssc[i].size()<<endl;
			ind = i;
			mx = ssc[i].size();
		}
	}

	cout<<"Largest SSC:\nindex = "<<ind<<", size = "<<ssc[ind].size()<<endl;
	for(int i=0; i<ssc[ind].size(); i++)
		cout<<ssc[ind][i]<<",";
	cout<<endl;


	//Now finding diameter
	findDia(ind);




	return 0;

}