#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    ll n,prev=-1;
    cin >> n;
    rep(i,100000){
        if (pow(i,2)<=n){
            prev=pow(i,2);
        }
        else{
            cout << prev << endl;
            break;
        }
    }
}