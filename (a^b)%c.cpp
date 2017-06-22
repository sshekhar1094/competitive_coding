#include <cstdio>
#include <iostream>
using namespace std;

int modpowIter(int a, int b, int c) {  // (a^b)%c
        int ans=1;
        while(b) {
                if(b & 1) // if b is odd
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b >>= 1;  // b = b/2
        }
        return ans;
}
int main() {
        int a=5,b=59,c=19,ans,ans1;
        ans = modpowIter(a,b,c);
        cout << ans << endl;
}
