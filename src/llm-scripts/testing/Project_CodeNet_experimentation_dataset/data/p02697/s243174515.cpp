#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    set<int> st;
    for(int i=1;i<n;i++){
        st.insert(i);
    }
    int k=1;
    int pr=-1;
    set<int> check;
    while(k<=m){
        int v=*rbegin(st);
        st.erase(v);
        while(pr-v==1||check.count(n-v)||2*v==n){
            v=*rbegin(st);
            st.erase(v);
        }
        pr=v;
        check.insert(v);
        printf("%d %d\n",k,k+v);
        k++;
    }
}