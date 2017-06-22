
/*
    Given a string print it in the ascending order of no of occurences of its characters
    eg: aabcdeaabbacbe,
        a->5, b->4, c->2, d->1, e->2;
        output-> dcceebbbbaaaaa
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
char s[105];
int arr[27];
map<char, int> m1;
//map<int, char> m2;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-'); c=getchar());
	if(c=='-') {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar()) i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

bool func(pair<int, int> fst, pair<int,int> sec){
    if(fst.second < sec.second ) return true;
    if(fst.second == sec.second){
        if(fst.first < sec.first) return true;
        else return false;
    }
    return false;
}

int main(){
    int t;
    rd(t);
    vector< pair<int,int> > v;
    pair<int, int> p;
    while(t--){
        scanf("%s", s);
        int i,tmp;
        for(i=0; i<=26; i++) arr[i] = 0;
        for(i=0; s[i] != NULL; i++)
            arr[s[i] - 97]++;

        for(i=0; i<26; i++){
            p = make_pair(i + 97, arr[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), &func);
        for(i=0; i<v.size(); i++){
            tmp = v[i].second;
            while(tmp--)
                printf("%c", v[i].first);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}
