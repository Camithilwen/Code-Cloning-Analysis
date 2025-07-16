#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> b, all(n+1);
    for(int i = n; i >= 1; i--) {
        int cnt = 0;
        for(int j = i; j <= n; j+=i) {
            if(all[j] == 1)
                cnt++;
        }
        
        if((cnt % 2 == 0 && a[i] == 1) ||
           (cnt % 2 == 1 && a[i] == 0)) {
            all[i] = 1;
            b.push_back(i);
        }
    }
    
    int bs = (int)b.size();
    
    cout << bs << endl;
    rep(i,bs) cout << b[i] << endl;
    
    
    return 0;
}


