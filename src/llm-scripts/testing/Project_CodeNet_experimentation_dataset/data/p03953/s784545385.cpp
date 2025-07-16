#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

vector<ll> & T(vector<ll> &ret,vector<ll> A,vector<ll> B){
    for(int i=0;i<B.size();i++){
        ret[i]=A[B[i]];
    }
    return ret;
}



int main(){
    ll n;
    cin>>n;
    vector<ll> x(n);
    for(auto &i:x){cin>>i;}
    ll m,k;
    cin>>m>>k;
    vector<ll> A(m);
    for(auto &i:A){cin>>i;}
    vector<ll> a(n-1);
    vector<ll> ans(n-1);
    for(int i=0;i+1<n;i++){ans[i]=a[i]=i;}
    for(int i=0;i<m;i++){
        A[i]--;
        swap(a[A[i]-1],a[A[i]]);
    }
    while(k>0){
        if(k&1){T(ans,ans,a);}
        T(a,a,a);
        k>>=1;
    }
    vector<ll> dp(n,x[0]);
    for(int i=0;i<n-1;i++){
        dp[i+1]=dp[i]+x[ans[i]+1]-x[ans[i]];
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<endl;
    }
    
    
    return 0;
}
