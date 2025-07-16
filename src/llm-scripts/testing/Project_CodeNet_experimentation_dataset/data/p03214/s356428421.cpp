#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e18;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll sum =0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }
    ll m = INF;
    for(int i=0;i<N;i++){
        m = min(m,abs(sum- N*a[i]));
    }
    for(int i=0;i<N;i++){
        if(abs(sum-N*a[i]) == m){
            cout << i << endl;
            break;
        }
    }
    return 0;
    
}