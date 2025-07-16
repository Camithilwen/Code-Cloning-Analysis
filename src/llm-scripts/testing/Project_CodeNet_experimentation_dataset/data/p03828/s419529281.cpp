#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    cin>>n;
    map<int,ll> mp;
    for(int i=2;i<=n;i++){
        int m=i;
        for(int j=2;j*j<=m;j++){
            while(m%j==0){
                mp[j]++;
                m/=j;
            }
        }
        if(m>1) mp[m]++;
    }
    ll ans=1;
    for(auto p:mp){
        ans*=p.second+1;
        ans%=MOD;
    }
    cout<<ans<<endl;

}