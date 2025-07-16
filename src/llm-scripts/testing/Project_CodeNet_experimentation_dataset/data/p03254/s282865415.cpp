#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define BIL ((ll)1e9)
#define MOD ((ll)1e9+7)
#define INF (1LL<<60)           //1LL<<63でオーバーフロー
#define inf (1<<29)             //1<<29でオーバーフロー

int main(int argc,char* argv[]){
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    for(auto &x:a)cin >> x;

    sort(a.begin(),a.end());

    if(a[0]>x){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> asum(n);
    asum[0]=a[0];
    int ans=-1;
    for(int i=1;i<a.size();i++){
        asum[i]=asum[i-1]+a[i];
        if(asum[i]==x){
            ans=i+1;
            break;
        }else if(asum[i]>x){
            ans=i;
            break;
        }
    }

    if(ans==-1){
        ans=n-1;
    }

    cout << ans << endl;

    return 0;
}
