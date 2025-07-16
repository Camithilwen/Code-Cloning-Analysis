#include <bits/stdc++.h>          
using namespace std;        
typedef long long ll;       

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i=0; i<N; i++) {
        cin >> A[i];
    }

    string ans = "YES";

    sort(A.begin(),A.end());
    /*
    for (ll i=0; i<N; i++) {
        cout << A[i];
    }
    cout << endl;
    */
    for (ll i=0; i<N-1; i++) {
        if (A[i]==A[i+1]) {
            ans = "NO";
            break;
        }
    }

    cout << ans << endl;
    
}