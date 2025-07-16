#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q; cin>>n>>m>>q;
   vector<vector<int>> a(n,vector<int> (n,0));
    for(int i=0;i<m;i++){
        int l,r; cin>>l>>r;
        l--; r--;
       a[l][r]++;
    }

    vector<vector<int>> s(n+1,vector<int> (n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
        }
    }

    for(int i=0;i<q;i++){
        int x,y; cin>>x>>y;
        x--;
        cout<<s[y][y]-s[x][y]-s[y][x]+s[x][x]<<endl;
    }
}