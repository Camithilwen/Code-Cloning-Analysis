#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

int main(){
    int N; cin >> N;
    vector<int> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    for(int i = N-1; i >= 0; i--){
        for(int j = 30; j >= 1; j--){
            ll key = pow(2, j) - A[i];
            if(key <= 0) break;
            auto itr = lower_bound(A.begin(), A.end(), key);
            if(*itr != key) continue;
            int d = distance(A.begin(), itr);

            if(i == d) {
                continue;
            }

            A.erase(A.begin()+i);
            A.erase(A.begin()+d);
            //cout << d << " " << i << " " << A.size() << endl;
            i--;
            ans++;
            
            break;
        }
    }
    cout << ans << endl;
}