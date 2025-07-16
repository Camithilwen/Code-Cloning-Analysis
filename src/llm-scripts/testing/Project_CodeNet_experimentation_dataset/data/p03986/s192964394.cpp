#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main() {
     string x;
     cin >> x;
     int n = x.size();
     stack<char> st;
     rep(i,n){
          if (st.empty()) st.push(x[i]);
          else if(st.top()=='S'){
               if(x[i]=='T'){
                    st.pop();
               }
               else st.push(x[i]);
          }
          else st.push(x[i]);
     }
     cout << st.size() <<endl;
}