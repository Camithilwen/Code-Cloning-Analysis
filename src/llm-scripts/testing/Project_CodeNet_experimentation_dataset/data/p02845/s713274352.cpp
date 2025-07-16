#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const int MAX = 510000;
static const ll MOD = 1000000007;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin>>A[i];
    vector<ll> color(3,0);

    ll ans = 1;

    for(int i=0; i<N; i++){
        ll kake = 0;
        for(int j=0; j<3; j++){
            if(color[j] == A[i]) kake++;
        }

        ans *= kake;
        ans %= MOD;

        for(int j=0; j<3; j++){
            if(color[j] == A[i]){
                color[j]++;
                break;
            }
        }
    }

    cout<<ans<<endl;
}