/*
    KNAPSACK PROBLEM: V vector having values of objects and W having wt of each object, Given a maximum wt C find max vlue
    Eg.
        v: 7 2 1 6 12
        W: 3 1 2 4 6
        C: 10
    However this was he solution made by me, below it is the solution from Geeks and Geeks
*/

#include <algorithm>
#include <iostream>
#include<vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include<stdio.h>
using namespace std;
int n,tab[1100][1100]={0}, V[1100], W[1100];

int KS(int c, int i){
    if(i>n){
        tab[c][i]=0;
        return 0;
    }
    if(c < W[i]){
        if(tab[c][i+1] == 0)
            tab[c][i+1] = KS(c,i+1);
        return tab[c][i+1];
    }
    else{
        if(tab[c][i+1] == 0)
            tab[c][i+1] = KS(c,i+1);
        if(tab[c - W[i]][i+1] == 0)
            tab[c-W[i]][i+1] = KS(c-W[i], i+1);
        return max( V[i]+tab[c-W[i]][i+1], tab[c][i+1] );
    }
}

int main()
{
    int c,ans;
    cout<<"Enter size and capacity";
    cin>>n>>c;
    cout<<"Value\n";
    for(int i=0; i<n; i++)
        cin>>V[i];
    cout<<"Weight\n";
    for(int i=0; i<n; i++)
        cin>>W[i];
    ans = KS(c,0);
    cout<<endl<<ans;
	return 0;
}


/*
#include<stdio.h>
int max(int a,int b)
{
        return a>b?a:b;
}
int Knapsack(int items,int weight[],int value[],int maxWeight)
{
        int dp[items+1][maxWeight+1];
        // dp[i][w] represents maximum value that can be attained if the maximum weight is w and
        //   items are chosen from 1...i
        // dp[0][w] = 0 for all w because we have chosen 0 items
        int iter,w;
        for(iter=0;iter<=maxWeight;iter++)
        {
                dp[0][iter]=0;
        }
        // dp[i][0] = 0 for all w because maximum weight we can take is 0
        for(iter=0;iter<=items;iter++)
        {
                dp[iter][0]=0;
        }
        for(iter=1;iter<=items;iter++)
        {
                for(w=0;w<=maxWeight;w++)
                {
                        dp[iter][w] = dp[iter-1][w]; // If I do not take this item
                        if(w-weight[iter] >=0)
                        {
                                // suppose if I take this item
                                dp[iter][w] = max(dp[iter][w] , dp[iter-1][w-weight[iter]]+value[iter]);
                        }
                }

        }
        return dp[items][maxWeight];
}
int main()
{
        int items;
        scanf("%d",&items);
        int weight[items+1],value[items+1];
        int iter;
        for(iter=1;iter<=items;iter++)
        {
                scanf("%d%d",&weight[iter],&value[iter]);
        }
        int maxWeight;
        scanf("%d",&maxWeight);
        printf("Max value attained can be %d\n",Knapsack(items,weight,value,maxWeight));
}

*/

