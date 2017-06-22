#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node* Insert(struct Node *head, int val){
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = val;
    tmp->next = head;
    head = tmp;
    return head;
}

void Print(struct Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void Reverse(struct Node **head, struct Node *tmp){
    if(tmp->next == NULL){
        *head = tmp;
        return ;
    }
    Reverse(head, tmp->next);
    struct Node *q;
    q = tmp->next;
    q->next = tmp;
    tmp->next = NULL;
}

struct Node* RevChunk(struct Node *head, int k){    //to reverse in chunks of k
    struct Node *prev, *nxt, *curr;
    prev=NULL; nxt=NULL; curr=head;
    int ct = 0;

    while(curr != NULL && ct<k){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        ct++;
    }

    if(nxt != NULL) head->next = RevChunk(nxt, k);
    return prev;

}

int main(){
    struct Node *head = NULL;
    head=Insert(head, 12); head=Insert(head, 22); head=Insert(head, 14); head=Insert(head, 2); head=Insert(head, 7);
    head=Insert(head, 17); head=Insert(head, 229); head=Insert(head, 30); head=Insert(head, 52); head=Insert(head, 1);

    cout<<"Original:";
    Print(head);

    Reverse(&head, head);
    cout<<"\n\nReversed: ";
    Print(head);

    int k=3;
    cout<<"\n\nReversed in chunks of "<<k<<": ";
    Reverse(&head, head);
    head = RevChunk(head, k);
    Print(head);

    return 0;
}
