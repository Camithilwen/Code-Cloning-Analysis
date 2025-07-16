#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, l; cin >> n >> l;
    int a[n];
    int sum0 = 0;
    rep(i, n){
        a[i] = i+l;
        sum0 += a[i];
    }
    int s = INF;
    bool minus = false;
    rep(i, n){
        if(s > abs(a[i])){
            if(a[i] < 0) minus = true;
            else minus = false;
            s = abs(a[i]);
        }
        s = min(s, abs(a[i]));
    }
    cout << (!minus? sum0-s: sum0+s) << endl;


    return 0;
}