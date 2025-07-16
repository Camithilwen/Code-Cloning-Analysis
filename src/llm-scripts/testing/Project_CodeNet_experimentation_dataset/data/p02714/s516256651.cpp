#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll N; cin >> N;
    string S; cin >> S;
    ll r=0,g=0,b=0;
    for(int i=0; i<N; i++) {
        if(S[i]=='R') r++;
        if(S[i]=='G') g++;
        if(S[i]=='B') b++;
    }
    ll sum = r*g*b;
    ll count = 0;
    for(ll i=0; i<N; i++) {
        for(ll j=i+1; j<N; j++) {
                ll k=2*j-i;
                if(k<N) {
                    if(S[i]!=S[j] && S[i]!=S[k] && S[j]!=S[k]) {
                    //cout << " i:" << i << " j:" << j << " k:" << k << endl; 
                    count++;
                    }
                }
            }
        }
    cout << sum-count << endl;
}