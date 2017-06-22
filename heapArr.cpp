#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int *heap, sz;

void heapify(int n){
    int t, l=2*n+1, r=2*n+2, mx=n;
    if(l<sz && heap[l] > heap[mx]) mx = l;
    if(r<sz && heap[r] > heap[mx]) mx = r;
    if(mx != n){
        swap(heap[mx], heap[n]);
        heapify(mx);
    }
}

void build(int arr[], int n){
    heap = arr;
    sz = n;
    while(n>0){
        n--;
        heapify(n);
    }
}

void Print(){
    for(int i=0; i<sz; i++) cout<<heap[i]<<" ";
}

void Remove(){
    int ans = heap[0];
    heap[0] = heap[sz-1];
    sz--;
    heapify(0);
    cout<<endl<<ans<<" Removed\n";
    cout<<"New heap:\n";
    Print();
}

void Insert(int x){
    sz++;
    heap[sz-1] = x;
    int p = (sz-2)/2;
    int c = sz-1;
    while(p>=0 && heap[p] < heap[c]){
        swap(heap[p], heap[c]);
        c = p;
        p = (c-1)/2;
    }
    cout<<endl<<x<<"Inserted\nNew heap:\n";
    Print();
}

int main(){
    int n;
    int arr[] = {1,8,3,2,4,5,6,7,2,1,15,26,34,12,17,89,54,12,132,56,48};
    n = sizeof(arr)/sizeof(arr[0]);
    build(arr, n);
    //for(int i=0; i<n; i++) cout<<i<<":"<<arr[i]<<endl;
    Remove();
    Insert(99);
    Insert(90);

    return 0;
}
