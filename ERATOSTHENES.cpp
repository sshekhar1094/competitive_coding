#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

void mark(bool arr[], int n, int a){
    int i=2,num;
    while((num=i*a) <= n){
        arr[num-1] = 1;
        i++;
    }
}

void Sieve(int n){
    if(n>=2){
        bool arr[n];
        memset(arr, 0, sizeof(arr));
        for(int i=1; i<n; i++){
            if(arr[i] == 0){
                cout<<i+1<<" ";
                mark(arr,n,i+1);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Primes upto???";
    cin>>n;
    Sieve(n);
    return 0;
}

