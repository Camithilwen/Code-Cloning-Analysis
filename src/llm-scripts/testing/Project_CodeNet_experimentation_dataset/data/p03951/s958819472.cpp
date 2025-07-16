#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int overlap = 0;
    for(int i = 1; i <= n; i++) {
        if (s.substr(n-i, i) == t.substr(0, i)) {
            overlap = i;
        }
            
    }
    cout << n*2 - overlap << endl;
    return 0;
}
