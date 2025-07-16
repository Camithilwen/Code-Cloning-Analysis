#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 10000000

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll sum=0;
    ll tmp=0;
    int count=0;
    
    rep(i,n){
        if(a[i]<0)count++;
        a[i]=abs(a[i]);
        sum+=a[i];
    }
    ssort(a);
    if(count%2==0){
        cout << sum << endl;
    }else{
        cout << sum-2*a[0] << endl;
    }
}