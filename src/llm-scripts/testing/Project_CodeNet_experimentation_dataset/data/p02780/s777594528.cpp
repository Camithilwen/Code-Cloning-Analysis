#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    int n,k;
    cin >> n >> k;
    int p[n];
    REP(i,n) cin >> p[i];
    int sumf=0,suml=0,maxs=0;
    REP(i,n){
        sumf+=p[i];
        if(i>=k){
            suml+=p[i-k];
            chmax(maxs,sumf-suml);
        }
    }
    if(n==k) maxs=sumf;
    double ans=(double)k/2 + (double)maxs/2;
    printf("%.7f\n",ans);

    return 0;
}