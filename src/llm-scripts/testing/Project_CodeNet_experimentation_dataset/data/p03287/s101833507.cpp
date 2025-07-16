#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> vec(N + 1);
    vec[0] = 0;
    rep(i,N){
        cin >> vec[i + 1];
    }
    rep(i,N){
        vec[i + 1] += vec[i];
    }
    rep(i,N + 1){
        vec[i] %= M;
    }
    sort(all(vec));
    ll ans = 0;
    ll count = 1;
    vec.push_back(-1);
    rep(i,N + 1){
        if (vec[i + 1] == vec[i]) count++;
        else{
            ans += (count - 1) * count / 2;
            count = 1;
        }
    }
    cout << ans << endl;
}