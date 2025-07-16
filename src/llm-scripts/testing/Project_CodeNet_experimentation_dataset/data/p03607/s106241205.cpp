#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, ans=0;
    map<int, int> mp;
    cin >> n;
    while(n--){
        cin >> x;
        if(!mp[x]){
            mp[x]=1;
            ans++;
        }else mp[x]=0, ans--;
    }
    cout << ans << endl;
}
int main(){
   solve();
}
