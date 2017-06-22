#include<iostream>
#include<stdio.h>
using namespace std;

template <class T>
inline void ri(T &i){
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

inline void fastWrite(int Number){

	if(Number==0){	putchar('0'); putchar('\n'); return; }
	int reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}
	while(reversedNumber){	putchar(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) putchar('0');
	putchar('\n');

}

int main(){
    int t;
    cout<<"Enter no\n";
    ri(t);
    fastWrite(t);

    //For reading strings
    char a[1000];
    cout<<"Enter string:";
    fgets(&a[0], 1000, stdin);
    fputs(a, stdout);
    cout<<"done";
    return 0;
}

