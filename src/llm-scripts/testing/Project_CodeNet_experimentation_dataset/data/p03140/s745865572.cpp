#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    string A,B,C;
    cin >> A >>B >>C;
    ll ans =0;
    for(int i=0;i<N;i++){
        set<char> s;
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);
        ans += (s.size()-1);
    }
    cout << ans << endl;
    return 0;
}