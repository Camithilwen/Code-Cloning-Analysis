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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    int n;
    cin>>n; 
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(n,0);
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int now=i+1;
        int widt=now;
        int num=0;
        for(;now<=n;now+=widt){
            num+=b[now-1];
        }
        if(num%2==a[i]){
            b[i]=0;
        }else{
            b[i]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<b.size();i++){
        if(b[i]) cout<<i+1<<" ";
    }
    cout<<endl;

}