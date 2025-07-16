#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
#define mod 100003
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define piiii pair<int,piii>
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
FO
#define no {cout<<"NO"<<endl;return;}
#define yes {cout<<"YES"<<endl;return;}

void solve(){
    int n,k;
    cin>>n>>k;
    long double maxx=0,sum=0;
    long double p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=k;i++){
        sum+=0.5*(p[i]+1);
    }
    maxx=max(maxx,sum);
    for(int j=k+1;j<=n;j++){
        //cout<<i<<" "<<j<<endl;
        sum-=0.5*(p[j-k]+1);
        sum+=0.5*(p[j]+1);
        maxx=max(maxx,sum);
    }
    cout<<setprecision(12)<<maxx;




    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
