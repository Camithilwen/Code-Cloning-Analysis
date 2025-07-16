#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;
bool dp[6410][20000];
int abs(int x,int y){
    if(x>=y) return x-y;
    else return y-x;
}
int main(){
    int h,w;
    cin >> h >> w;
    vector<int> a(h*w), b(h*w);
    rp(i,h*w) cin >> a[i];
    rp(i,h*w) cin >> b[i];
    rp(i,6410){
        rp(j,20000) dp[i][j]=false;
    }
    int m=0;
    rp(i,h*w) m=max(m,abs(a[i],b[i]));
    dp[0][abs(a[0],b[0])]=true;
    for(int i=1; i<h*w; i++){
        int dif=abs(a[i],b[i]);
        if(i%w){
            for(int k=0; k<=(h+w)*m;k++){
                if(dp[i-1][k]){
                    dp[i][abs(k,dif)]=true;
                    if(k+dif<=(h+w)*m*2) dp[i][k+dif]=true;
                }
            }
        }
        if(i>=w){
            for(int k=0; k<=(h+w)*m;k++){
                if(dp[i-w][k]){
                    dp[i][abs(k,dif)]=true;
                    if(k+dif<=(h+w)*m*2) dp[i][k+dif]=true;
                }
            }
        }
    }
    int ans;
    int c=0;
    while(1){
        if(dp[h*w-1][c]){
            ans=c;
            break;
        }
        c++;
    }
    cout << ans << endl;
    return 0;
}