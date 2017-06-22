#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;

char str[100009];

bool vowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
    return 0;
}

int main(){
    scanf("%s", str);
    int mx=0, len=0;
    for(int i=0; str[i]!=NULL; i++){\
        if(vowel(str[i])) len++;
        else len=0;
        mx = max(len, mx);
    }

    printf("%d", mx);

    return 0;
}
