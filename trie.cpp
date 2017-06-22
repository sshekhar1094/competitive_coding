#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int prefix;
    bool word;
    struct Node *next[26];
};

struct Node* getNode(){
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->prefix = 0;
    root->word = 0;
    for(int i=0; i<26; i++) root->next[i] = NULL;
    return root;
}

void Insert(struct Node *tmp, string str){
    int n = str.size();
    for(int i=0; i<n; i++){
        int ind = str[i] - 'a';
        if(tmp->next[ind] == NULL) tmp->next[ind] = getNode();
        tmp->prefix++;
        tmp = tmp->next[ind];
    }
    cout<<str<<" inserted\n";
    tmp->word = 1;
    tmp->prefix++;
}

void Print(struct Node *tmp, string str){
    cout<<str;
    if(tmp->word == 1) cout<<", word";
    cout<<", Prefix = "<<tmp->prefix<<endl;
    for(int i=0; i<26; i++){
        if(tmp->next[i] != NULL)
            Print(tmp->next[i], str + char('a'+i));
    }
}

void Search(struct Node *tmp, string str){
    int n = str.size();
    for(int i=0; i<n; i++){
        int ind = str[i] - 'a';
        if(tmp->next[ind] == NULL){
            cout<<str<<" not found\n";
            return;
        }
        tmp = tmp->next[ind];
    }
    cout<<str<<" found\n";
}

int main(){
    struct Node *root = getNode();
    string str;
    Insert(root, "the"); Insert(root, "a"); Insert(root, "there"); Insert(root, "answer");
    Insert(root, "any"); Insert(root, "by"); Insert(root, "bye"); Insert(root, "their");

    cout<<"\nContents of trie:\n";
    Print(root, str);

    cout<<"\nSearching:\n";
    Search(root, "there"); Search(root, "any"); Search(root, "theree"); Search(root, "bc");
    return 0;
}
