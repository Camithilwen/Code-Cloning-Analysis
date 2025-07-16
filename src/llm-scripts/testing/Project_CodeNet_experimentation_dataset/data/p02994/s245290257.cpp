#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, l;
    cin >> n >> l;
    
    int mn = 1000, sum = 0;
    rep(i,n) {
        int t = i + l;
        sum += t;
        mn = min(abs(t),abs(mn));
        if(t < 0)
            mn *= -1;
    }
    
    cout << sum - mn << endl;
    
    
    
    return 0;
}
