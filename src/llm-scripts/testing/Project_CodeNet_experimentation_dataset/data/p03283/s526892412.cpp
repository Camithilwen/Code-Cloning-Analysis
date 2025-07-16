#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(void){
    int n,m,q;cin >> n >> m >> q;
    vector<vector<int>> s(n+2,vector<int>(n+2,0));
    
    int num[575][770] = {};
    rep(i,m){
        int l,r;cin >> l >> r;
        num[max(l,r)-1][min(r,l)-1]++;
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < n+1;j++){
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + num[i-1][j-1];
        }
    }
    
    rep(i,q){
        int alina,gray;cin >> alina >> gray;
        int l = max(alina,gray),r = min(alina,gray);
        
        int sum = s[l][l] - s[r-1][l] - s[l][r-1] + s[r-1][r-1];
        
        cout << sum << endl;
    }
}