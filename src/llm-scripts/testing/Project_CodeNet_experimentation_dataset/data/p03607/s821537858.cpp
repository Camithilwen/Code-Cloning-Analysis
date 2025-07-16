#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans=n;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            ans-=2;
            i++;
        }
    }
    cout << ans << endl;
}
