#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> L(M+1);
    vector<ll> R(M+1);
    for(int i = 1; i <= M; ++i) cin >> L[i] >> R[i];
    if(*min_element(R.begin()+1, R.end())-*max_element(L.begin()+1, L.end()) >= 0)cout << *min_element(R.begin()+1, R.end())-*max_element(L.begin()+1, L.end()) +1 << endl;
    else cout << 0 << endl;
    return 0;
}