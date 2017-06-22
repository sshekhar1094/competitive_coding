#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

/*
    This code does Quick Sort taking the last element of the array as the pivot element
*/

int part(int A[], int l, int n){
    int i=l-1, pvt = A[n],j;
    for(j = l; j<n; j++){
        if(A[j] < pvt){
            i++;
            swap(A[j], A[i]);
        }
    }
    swap(A[i+1], A[n]);
    return i+1;
}

void QuickSort(int A[], int l, int r){
    if(l<r){
        int q = part(A,l,r);
        QuickSort(A,l, q-1);
        QuickSort(A,q+1,r);
    }
}

int main(){
    int A[] = {3,8,2,5,1,4,7,6};
    //int B[8];
    QuickSort(A,0,7);
    for(int i=0; i<8; i++)
        cout<<A[i]<<" ";
    return 0;
}
