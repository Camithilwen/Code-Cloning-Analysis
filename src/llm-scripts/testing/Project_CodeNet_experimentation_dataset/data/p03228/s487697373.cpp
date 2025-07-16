#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> AB(2);
    for (int i=0;i<2;++i) cin >> AB[i];
    int K; cin >> K;
    for (int i=0;i<K;++i){
        if (AB[i&1]&1) --AB[i&1];
        AB[(i&1)^1]+=AB[i&1]/2;
        AB[i&1]/=2;
    }
    cout << AB[0] << ' ' << AB[1] << '\n';
}