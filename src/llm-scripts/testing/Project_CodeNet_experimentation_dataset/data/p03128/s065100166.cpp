#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
void changeString(string &t,string p){
    if(t=="0") t=p;
    else if(t.size()<p.size()) t=p;
    else if(t.size()==p.size()){
        if(t<p) t=p;
    }
}
string dp[MAX];
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    sort(ALL(a));
    REP(i,m)IN(a[i]);
    int num[10]={0,2,5,5,4,5,6,3,7,6};
    REP(i,MAX){
        dp[i]="0";
    }
    dp[0]="";
    REP(i,n+1){
        if(dp[i]=="0")continue;
        REP(j,m){
            changeString(dp[i+num[a[j]]],dp[i]+(char)(a[j]+'0'));
        }
    }
    OUT(dp[n]);
    return 0;
}