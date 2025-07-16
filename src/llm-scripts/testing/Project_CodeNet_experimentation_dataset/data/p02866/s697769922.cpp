#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77 ;
int mod = 998244353;
int cnt[N];
int32_t main(){
    fast;
    int n ; cin >> n ;
    int in = 0;
    for(int i = 0 ; i < n ; ++i){
        int a ; cin >> a;
        cnt[a]++;
        if(i==0) in = a;
    }
    int ans = (int)((cnt[0] == 1) && (in == 0));
    for(int i = 1 ; i <= 1e5 ;++i){
        for(int j = 0 ;j < cnt[i] ; ++j){
            ans = (ans*cnt[i-1]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}