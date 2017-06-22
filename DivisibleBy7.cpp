#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool isDivisibleBy7(char a[], int n){
    long long s=0,t;
    for(int i=n-1,j=0; i>=0; i=i-3,j++){
        if(i==1) t = (a[1]-48) + 10*(a[0]-48);
        else if(i==0) t = a[0]-48;
        else t = (a[i] - 48) + 10*(a[i-1]-48) + 100*(a[i-2]-48);
        if(j%2==0)
            s = s+t;
        else s = s-t;
    }
    if(s%7==0) return true;
    else return false;
}

int main()
{
    char a[300]; //here we take 300 as the size of input string
    cout<<"Enter:";
    cin>>a;
    if(isDivisibleBy7(a,300))
        cout<<"Divisible by 7";
    else
        cout<<"not divisible by 7";
    return 0;
}
