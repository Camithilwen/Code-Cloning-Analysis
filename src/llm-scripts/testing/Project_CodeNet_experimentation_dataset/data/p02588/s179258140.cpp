#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vv = vector<vi>;



int main(){
    
    int n;cin>>n;
    vv faclist(19, vi (19, 0));
    
    rep(i,n){
        double a;cin>>a;
        ll anum = a*1e9+0.5;
        
        //llとして読み込み, 2と5の冪を計算
        int fac2 = -9, fac5 = -9;
        
        while( fac2<10 && anum%2 == 0 ){
            fac2++;
            anum /= 2;
        }
        
        while( fac5<10 && anum%5 == 0 ){
            fac5++;
            anum /= 5;
        }
        
        faclist[min(18,fac2+9)][min(18,fac5+9)]++;
    }
    
    //個数累積のリストを作る
    vv acclist = faclist;
    
    
    rep(i,19){
        for(int j=17; j>=0; j--){
            acclist[i][j] += acclist[i][j+1];
        }
    }
    rep(j,19){
        for(int i=17; i>=0; i--){
            acclist[i][j] += acclist[i+1][j];
        }
    }
    
    ll ans = 0;
    
    rep(i,19)rep(j,19){
        if(!faclist[i][j])continue;
        
        if(i>8 && j>8)ans += faclist[i][j] * (acclist[18-i][18-j]-1);
        else ans += faclist[i][j] * acclist[18-i][18-j];
    }
    
    cout << ans/2 << endl;
    return 0;
}