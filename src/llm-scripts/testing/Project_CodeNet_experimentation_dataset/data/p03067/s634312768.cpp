#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    if(A <= B){
        for(ll i = A; i <= B; i++){
            if(i == C){
                cout << "Yes";
                return 0;
            }
        }
    }else{
        for(ll i = A; i >= B; i--){
            if(i == C){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}