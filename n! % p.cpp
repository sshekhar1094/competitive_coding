#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

//Program to find (n!)%(p) when p is prime


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
    long long t,n,p,res;
    rd(t);
    while(t--){
        rd(n); rd(p);
        if(n >= p){
            printf("0\n");
            continue;
        }
        if(n==1) {
            printf("1\n");
            continue;
        }
        if(n == p-1){
            printf("%lld\n", n);
            continue;
        }
        res = 1;
        for(long long i=n+1;i <= p-2 ;i++)
            res = (res*i)%p;
        res = fastexp(res,p-2,p);
        printf("%lld\n", res);
    }
    return 0;
}

