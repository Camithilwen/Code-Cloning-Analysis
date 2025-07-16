#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    string tmp_s;
    rep(i, s.length()) {
        tmp_s += s[i];
        if ( tmp_s + "FESTIVAL" == s ) break; 
    }
    cout << tmp_s << endl;
    return 0;
}
