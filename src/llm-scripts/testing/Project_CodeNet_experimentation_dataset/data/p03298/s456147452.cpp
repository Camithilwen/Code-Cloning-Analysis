#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

vector<int> tovec(ll x, int N){
    vector<int> vec;
    rep(i, N){
        if(x % 2 == 0) vec.push_back(0);
        else vec.push_back(1);
        x /= 2;
    }
    return vec;
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    string L, R;
    rep(i, N){
        L += S[i];
        R += S[2*N-1-i];
    }
    ll e[N+1];
    e[0] = 1;
    rep(i, N) e[i+1] = e[i]*2;
    map<pair<string, string>, ll> lmp, rmp;
    rep(i, e[N]){
        vector<int> vec = tovec(i, N);
        string l1, l2, r1, r2;
        rep(i, N){
            if(vec[i] == 0){
                l1 += L[i];
                r1 += R[i];
            }
            else{
                l2 += L[i];
                r2 += R[i];
            }
        }
        pair<string, string> p1 = make_pair(l1, l2), p2 = make_pair(r1, r2);
        if(lmp.count(p1)) lmp[p1]++;
        else lmp[p1] = 1;
        if(rmp.count(p2)) rmp[p2]++;
        else rmp[p2] = 1;
    }
    ll ans = 0;
    map<pair<string, string>, ll>::iterator ite;;
    ite = lmp.begin();
    while(ite != lmp.end()){
        if(rmp.count(ite->first)){
            ans += ite->second * rmp[ite->first];
        }
        ite++;
    }
    cout << ans << endl;
}