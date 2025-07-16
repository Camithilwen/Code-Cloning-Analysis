#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i=(a);i<ll(b);i++)
#define rep(i,b) loop(i,0,b)

void draw(char g[20][20], int ci, int cj){
    g[ci][cj] = '0';
    int di[] = {0,0,1,-1};
    int dj[] = {1,-1,0,0};
    rep(d,4){
        int ni = ci + di[d];
        int nj = cj + dj[d];
        if(ni >= 12 || nj >= 12 || ni < 0 || nj < 0 || g[ni][nj] == '0') continue;
        draw(g,ni,nj);
    }
}

int solve(char g[20][20]){
    int ans = 0;
    rep(i,12)rep(j,12){
        if(g[i][j] == '1'){
            ++ans;
            draw(g,i,j);
        }
    }
    return ans;
}

int main(){
    char g[20][20];
    while(~scanf("%s",g[0])){
        rep(i,11) scanf("%s",g[i+1]);
        printf("%d\n",solve(g));
    }
}