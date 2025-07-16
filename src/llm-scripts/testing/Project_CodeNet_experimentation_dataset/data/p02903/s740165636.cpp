#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
 
 
 
int main() {
    int H,W,A,B;
    cin>>H>>W>>A>>B;
    int M[H+1][W+1];
    rep3(i,H){
        rep3(j,W){
            if(((i<=B)&&(j<=A))||((i>B)&&(j>A))){
                M[i][j]=1;
            }
            else{
                M[i][j]=0;
            }
        }
    }
    rep3(i,H){
        rep3(j,W){
            if(j!=W){
                cout<<M[i][j];
            }
            else{
                cout<<M[i][j]<<endl;
            }
        }
    }
    
 
    
   
return 0;
}
