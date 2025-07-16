#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int n;
vector <long long> L;

void solve(){
    sort(all(L));
    int ans = 0;

    for(int i=0; i<=n-3; i++){
        for(int j=i+1; j<=n-2; j++){
            for(int k=j+1; k<=n-1; k++){
                if(L[i] != L[j] && L[j] != L[k]){
                    if(L[k] < L[i] + L[j]){
                        ans ++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    cin >> n;
    rep(i,n){
        int l;
        cin >> l;
        L.push_back(l);
    }

    solve();
}




