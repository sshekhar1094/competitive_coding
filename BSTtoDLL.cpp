/*
    Given a binary search tree objective is to convert the leaves of bst into a doubly lunked list without using any extra memory, ie
    you can not create andother linked list and keep attaching leaves to it. the right pointer of leaf points to next and left points
    to previous.
*/

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int val;
    struct Node *left, *right;
};

struct Node* Insert(struct Node *root, int data){
    if(root == NULL){
        root = (struct Node*)malloc(sizeof(struct Node));
        root->val = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->val)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void printbfs(struct Node *root){
    if(root==NULL) return;
    queue<struct Node*> Q;
    struct Node *top;
    Q.push(root);
    while(!Q.empty()){
        top = Q.front();
        cout<<top->val<<" ";
        Q.pop();
        if(top->left != NULL) Q.push(top->left);
        if(top->right != NULL) Q.push(top->right);
    }
}

void Leaf(struct Node *root){
    if(root->left == NULL && root->right==NULL){
        cout<<root->val<<" ";
        return;
    }
    if(root->left != NULL) Leaf(root->left);
    if(root->right != NULL) Leaf(root->right);
}

struct Node* extractLeaves(struct Node *root, struct Node **head){
    if(root == NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        //a leaf
        //attach to the head of the DLL
        root->right = *head;
        //make previous heads left point to this
        if(*head != NULL) (*head)->left = root;
        //now this becomes head of DLL
        *head = root;
        return NULL; //the leaf now detached from parent
    }
    //if not a leaf node then further travers
    //since we are attaching each node to begin trverse right side first
    root->right = extractLeaves(root->right, head);
    root->left = extractLeaves(root->left, head);
    return root;
}

void printDLL(struct Node *head){
    if(head == NULL) return;
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->right;
    }
}

int main(int argc, char *argv[]){
    struct Node *root = NULL;   //root for BST
    struct Node *head = NULL;   //head for DLL
    root = Insert(root, 34); root = Insert(root, 43); root = Insert(root, 26); root = Insert(root, 31);
    root = Insert(root, 27); root = Insert(root, 28); root = Insert(root, 18); root = Insert(root, 59); root = Insert(root, 41);
    cout<<"BFS:";
    printbfs(root);
    cout<<"\nLeaf Nodes:";
    Leaf(root);

    extractLeaves(root, &head);
    cout<<"\nDLL:";
    printDLL(head);
    cout<<"\nNew bfs of tree:";
    printbfs(root);
    return 0;
}
