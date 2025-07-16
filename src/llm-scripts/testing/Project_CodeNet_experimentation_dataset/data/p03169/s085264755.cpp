#include <iostream>
#include <bits/stdc++.h>
#define mod 998244353
#define point complex<double>
#define pi acos(-1)
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ld n, dp[305][305][305];
ld solve(int i, int y, int j){
    if(i+y+j==0)
        return 0;
    if(dp[i][y][j]!=-1)
        return dp[i][y][j];
    ld res=1, c0 = ( i + y + j);
    if(i)res+=solve(i-1, y+1, j)*((ld)i)/n;
    if(y)res+=solve(i, y-1, j+1)*((ld)y)/n;
    if(j)res+=solve(i, y, j-1)*((ld)j)/n;
    return dp[i][y][j]=res / c0 * n;
}
int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        cin>>n;
        int c1=0, c2=0, c3=0;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(x==1)c1++;
            else if(x==2)c2++;
            else c3++;
        }
        for(int i=0; i<305; i++){
            for(int y=0; y<305; y++){
                for(int j=0; j<305; j++){dp[i][y][j]=-1;}
            }
        }
        cout<<fixed<<setprecision(9)<<solve(c3, c2, c1)<<'\n';
    }

    return 0;
}
