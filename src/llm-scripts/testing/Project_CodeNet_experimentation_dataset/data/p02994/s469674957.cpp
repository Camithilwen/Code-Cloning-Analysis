#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<ll>>;
#define MAX 1000000007

int main()
{
    int n;double l;
    cin >> n >> l;
    vector<double> taste(n);
    rep(i,n){
        taste[i]=l+i+1-1;
    }
    double sum=0;
    rep(i,n){
        sum+=taste[i];
    }
    
    int ans_i=MAX;
    int p;
    rep(i,n){
        if(abs(taste[i]-0)<ans_i){
            p=i;
            ans_i=abs(taste[i]-0);
        }
    }
    sum-=taste[p];
    cout << sum << endl;
}