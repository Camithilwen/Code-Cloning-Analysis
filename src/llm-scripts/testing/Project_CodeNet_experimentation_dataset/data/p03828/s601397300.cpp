#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

constexpr ll mod = 1000000007;

int main() {
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    for(int i = 2; i <= n; i++) {
        int m = i;
        for(int j = 2; j <= n; j++) {
            while(m % j == 0) {
                mp[j]++;
                m /= j;
            }
        }
    }
    ll ans = 1;
    for(auto c : mp) {
        ans *= c.second+1;
        ans %= mod;
    }
    printf("%ld\n",ans);
}