#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, x; cin >> N >> x;
    ll ans = 0;
    ll prev; cin >> prev;
    for (int i = 1; i < N; i++){
        ll num; cin >> num;
        ll sum = prev + num;
        if(sum<=x){
            prev = num;
            continue;
        }

        ans += sum-x;
        if(sum-x > num) num = 0;
        else num = num - (sum - x);

        prev = num;
    }
    cout << ans << endl;


}
