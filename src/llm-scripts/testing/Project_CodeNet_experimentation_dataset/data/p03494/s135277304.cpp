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
    cin >> n;

    vector<ll> a(n);
    for(auto &x:a)cin >> x;

    int ans=-1;
    for(int i=0;i<30;i++){
        for(int j=0;j<n;j++){
            if(a[j]%2==1){
                ans=i;
                break;
            }
            a[j]=a[j]/2;
        }
        if(ans!=-1)break;
    }

    cout << ans << endl;

    return 0;
}
