/*  Segment tree which along with maximum element in each range also store the frequency of max element.
    Question: https://www.hackerrank.com/contests/codeagon/challenges/sherlock-and-subarray-queries
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;
map<int, pair<int,int> > tree;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

void construct(int input[], int low, int high, int pos){
    if(low == high){
        tree[pos].first = input[low];
        tree[pos].second = 1;
        return;
    }
    int mid = (low + high)/2;
    construct(input, low, mid, 2*pos + 1);
    construct(input, mid+1, high, 2*pos + 2);
    tree[pos].first = max(tree[2*pos + 1].first, tree[2*pos + 2].first);
    if(tree[2*pos + 1].first == tree[2*pos + 2].first)
        tree[pos].second = tree[2*pos + 1].second + tree[2*pos + 2].second;
    else if(tree[2*pos + 1].first > tree[2*pos + 2].first)
        tree[pos].second = tree[2*pos + 1].second;
    else
        tree[pos].second = tree[2*pos + 2].second;
}

pair<int, int> func(int qlow, int qhigh, int low, int high, int pos){
    if(qlow<=low && qhigh>=high)
        return make_pair(tree[pos].first, tree[pos].second);
    if(qlow>high || qhigh<low)
        return make_pair(-1, 0);
    int mid = (low + high)/2;
    pair<int, int> p1 = func(qlow, qhigh, low, mid, 2*pos + 1);
    pair<int, int> p2 = func(qlow, qhigh, mid+1, high, 2*pos + 2);
    if(p1.first > p2.first) return p1;
    else if(p1.first < p2.first) return p2;
    else return make_pair(p1.first, p1.second+p2.second);
}

int main(){
    int n,m,l,r, t,mx,ct;
    rd(n); rd(m);
    int arr[n];
    for(int i=0; i<n; i++)
        rd(arr[i]);
    construct(arr, 0, n-1, 0);
    //for(int i=0; i<tree.size(); i++)
        //cout<<i<<":"<<tree[i].first<<":"<<tree[i].second<<endl;
    for(int i=0; i<m; i++){
        rd(l); rd(r);
        l--; r--;
        pair<int, int> p = func(l, r, 0, n-1, 0);
        cout<<p.second<<endl;
    }
    return 0;
}
