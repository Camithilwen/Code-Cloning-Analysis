#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int INF = 1e9+5;

int main(){
 int N;
     cin>>N;
     vector<pair<int,int>> A,B;
     rep(i,N){
         int x,y;cin>>x>>y;
         A.push_back({y,x});
     }
     rep(i,N){
         int x,y;cin>>x>>y;
         B.push_back({x,y});
     }
     sort(all(A), greater<pair<int, int>>());
     sort(all(B));
     vector<bool> f(N, false);
     //cの小さい順
     rep(i,N){
         int c = B[i].first;
         int d = B[i].second;
         //bの大きい順
         rep(j,N){
             int a = A[j].second;
             int b = A[j].first;
             if(f[j])continue;
             if(a < c && b < d){
                 f[j] = true;
                 break;
             }
         }
     }
     int cnt =0;
     rep(i,N){
         if(f[i])cnt++;
     }
     cout<<cnt<<endl;
}