#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int x,y;
    scanf("%d%d",&x,&y);
    ll ans = 0;
    if(x == 3) ans += 100000;
    else if(x == 2) ans += 200000;
    else if(x == 1) ans += 300000;
    if(y == 3) ans += 100000;
    else if(y == 2) ans += 200000;
    else if(y == 1) ans += 300000;
    if(x == 1 && y == 1) ans += 400000;
    printf("%ld\n",ans);
}