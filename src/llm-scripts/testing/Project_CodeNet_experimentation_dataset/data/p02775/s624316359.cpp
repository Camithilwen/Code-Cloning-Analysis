#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
signed main(){
    string N;
    cin >> N;
    int ans = 0;
    bool kuriage = false;
    for(int i = N.size()-1; i >= 0; i--) {
        int keta = (int)(N[i]-'0');
        if (kuriage) {
            keta++;
        }
        kuriage = false;
        if (keta > 5 || (keta == 5 && i > 0 && (int)(N[i-1]-'0') > 4) ) {
            ans+=10-keta;
            kuriage = true;
        }
        else {
            ans+=keta;
        }
    }
    if (kuriage) {
        ans++;
    }
    cout << ans << endl;
}

