#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[505][505];
bool chk[23333333];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
int nxtPrime(int&x){
    auto chk=[&](int x){
        if(x<2)return false;
        for(int i=2;i*i<=x;i++)
            if(x%i==0)
                return false;
        return true;
    };
    do x++;while(!chk(x));
    ::chk[x]=true;
    return x;
}
void CCC(int n){
    map<int,pair<int,int>>s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(s.count(a[i][j])){
                cout<<s[a[i][j]].first<<" "<<s[a[i][j]].second<<" "<<i<<" "<<j<<"\n";
                break;
            }
            s[a[i][j]]=make_pair(i,j);
        }
}
void solve(int n){
    int p=0;
    for(int i=1,j=n-(~n&1);i<=n;i++,j--)
        if(!a[i][j]&&1<=j&&j<=n)
            a[i][j]=nxtPrime(p);
    for(int i=n,j=n;i>=1;i--,j--)
        if(!a[i][j])
            a[i][j]=nxtPrime(p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((i+j)%2==0){
                if(a[i][j])continue;
                auto get=[&](int dx,int dy)->ll{
                    int x=i,y=j;
                    while(1<=x&&x<=n&&1<=y&&y<=n){
                        if(chk[a[x][y]])return a[x][y];
                        x+=dx,y+=dy;
                    }
                    return 1;
                };
                a[i][j]=get(+1,+1)*get(+1,-1)*get(-1,+1)*get(-1,-1);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((i+j)%2==1){
                auto upd=[&](int dx,int dy){
                    if(a[i+dx][j+dy])
                        a[i][j]=lcm(a[i][j],a[i+dx][j+dy]);
                };
                a[i][j]=1;
                upd(+1,0);
                upd(-1,0);
                upd(0,+1);
                upd(0,-1);
                a[i][j]++;
            }
}
int main(){
    solve(500);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" \n"[j==n];
    return 0;
}