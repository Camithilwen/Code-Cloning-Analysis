#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    map<ll, ll> M;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(!M.count(A[i])) M[A[i]] = 1;
        else M[A[i]]++;
    }
    ll Max = 0, preMax = 0;
    for(auto p: M) {
        if(p.second >= 4) {
            if(p.first > Max) {
                preMax = p.first;
                Max = p.first;
            }
            else if(p.first > preMax) {
                preMax = p.first;
            }
        }
        else if(p.second >= 2) {
            if(p.first > Max) {
                preMax = Max;
                Max = p.first;
            }
            else if(p.first > preMax) {
                preMax = p.first;
            }
        }
    }
    ll ans = Max * preMax;
    cout << ans << endl;
    return 0;
}