#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <set>
using namespace std;

struct Node{
    float val;
    struct Node *left, *right;
};

struct Node* Insert(struct Node* root, float data){
    if(root == NULL){
        root = (struct Node*)malloc(sizeof(Node));
        root->val = data;
        root->right = root->left = NULL;
    }
    else if(data <= root->val)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

bool Search(struct Node* root, float data){
    if(root == NULL) return false;
    else if(data == root->val) return true;
    else if(data <= root->val) return Search(root->left, data);
    else return Search(root->right, data);
}

void PrintDFS(struct Node* root){
    if(root == NULL) return;
    else{
        cout<<root->val<<" ";
        PrintDFS(root->left);
        PrintDFS(root->right);
    }
}

void PrintZigzag(struct Node* root){
    stack<struct Node* > st1, st2;
    //Alternately use st1 and st2, always put right child first
    st1.push(root);
    bool flag = 1; //if 1 insert right child first and vice versa
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            struct Node* current = st1.top();
            cout<<current->val<<" ";
            st1.pop();
            if(flag == 1){
                if(current->right != NULL) st2.push(current->right);
                if(current->left != NULL)  st2.push(current->left);
            }
            else{
                if(current->left != NULL)  st2.push(current->left);
                if(current->right != NULL) st2.push(current->right);
            }
        }
        flag = !flag;
        while(!st2.empty()){
            struct Node* current = st2.top();
            cout<<current->val<<" ";
            st2.pop();
            if(flag == 1){
                if(current->right != NULL) st1.push(current->right);
                if(current->left != NULL)  st1.push(current->left);
            }
            else{
                if(current->left != NULL)  st1.push(current->left);
                if(current->right != NULL) st1.push(current->right);
            }
        }
        flag = !flag;
    }
}

void PrintBFS(struct Node *root){
    if(root == NULL) return;
    queue<struct Node* > Q;
    Q.push(root);
    while(!Q.empty()){
        struct Node* current = Q.front();
        Q.pop();
        cout<<current->val<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
    }
}

int main(){
    struct Node *root = NULL;
    int n,t;
    //Uncomment if you want to give choice of insert or search in BST
    /*
    cout<<"Choice Menu:\n1.Insert\n2.Search\n3.Exit\n";
    while(1){
        cout<<"Enter choice:";
        cin>>n;
        if(n==3) break;
        else if(n == 1){
            cout<<"Enter value to be inserted:";
            cin>>t;
            root = Insert(root, t);
        }
        else{
            cout<<"Enter value to be searched:";
            cin>>t;
            cout<<Search(root, t)<<endl;
        }
        cout<<"DFS:";
        PrintDFS(root);
    }*/
    root = Insert(root, 5);  root = Insert(root, 11);  root = Insert(root, 3);  root = Insert(root, 7);
    root = Insert(root, 2);  root = Insert(root, 9);  root = Insert(root, 1);  root = Insert(root, 0);
    root = Insert(root, 4);  root = Insert(root, 2);  root = Insert(root, 3.5);  root = Insert(root, 4.5);
    root = Insert(root, 6);  root = Insert(root, 3.3);  root = Insert(root, 3.7);  root = Insert(root, 4.3);
    root = Insert(root, 4.7);  root = Insert(root, 8);  root = Insert(root, 10);
    cout<<"DFS:";
    PrintDFS(root);
    cout<<endl<<"BFS:";
    PrintBFS(root);
    cout<<endl<<"ZigZag:";
    PrintZigzag(root);

    return 0;
}
