#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

template <class T>
inline void rd(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

long long fastexp(long long a,long long b,long long mod){
    long long res;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    res = fastexp(a,b/2,mod)%mod;
    if(b%2==0)
        return (res*res)%mod;
    else
        return ( ( (res*res)%mod)*a)%mod;
}

int main(){
    cout<<fastexp(5,3,1000);
    return 0;
}

