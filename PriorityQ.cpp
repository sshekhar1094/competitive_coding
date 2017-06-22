#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class myComparator{
    bool reverse;

public:
    myComparator(const bool& revparam=false){
        reverse = revparam;
        //max heap by default, if reverse is true min-heap
    }
    bool operator() (const int& lhs, const int& rhs) const{
        if(reverse) return (lhs > rhs); //min heap
        else return (lhs<rhs);
    }

};

int main(){
    int arr[] = {10, 50, 60, 20};
    priority_queue<int> first(arr, arr+4); //default max heap
    priority_queue<int, vector<int>, greater<int> > second (arr,arr+4); //min-heap

    // using mycomparison:
    typedef priority_queue<int, vector<int>, myComparator> mypq_type;

    mypq_type third(myComparator(true)); //custom min heap;
    third.push(10); third.push(50); third.push(60); third.push(20);

    cout<<"\nDefault heap:\n";
    while(!first.empty()){
        cout<<first.top()<<" ";
        first.pop();
    }

    cout<<"\n\nHeap using greater function:\n";
    while(!second.empty()){
        cout<<second.top()<<" ";
        second.pop();
    }

    cout<<"\n\nHeap using custom comparator function:\n";
    while(!third.empty()){
        cout<<third.top()<<" ";
        third.pop();
    }

    return 0;
}
