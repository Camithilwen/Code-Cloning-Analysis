#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin >> h >> w;
    int a[h][w],b[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> b[i][j];
        }
    }
    const int vmax=12800;
    bool c[h][w][2*vmax]={false};
    c[0][0][a[0][0]-b[0][0]+vmax]=true;
    c[0][0][b[0][0]-a[0][0]+vmax]=true;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<2*vmax;k++){
                if(!c[i][j][k]){
                    continue;
                }
                if(i<h-1){
                    c[i+1][j][k+a[i+1][j]-b[i+1][j]]=true;
                    c[i+1][j][k+b[i+1][j]-a[i+1][j]]=true;
                }
                if(j<w-1){
                    c[i][j+1][k+a[i][j+1]-b[i][j+1]]=true;
                    c[i][j+1][k+b[i][j+1]-a[i][j+1]]=true;
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<2*vmax;i++){
        if(c[h-1][w-1][i]){
            chmin(ans,abs(i-vmax));
        }
    }
    cout << ans << endl;
}