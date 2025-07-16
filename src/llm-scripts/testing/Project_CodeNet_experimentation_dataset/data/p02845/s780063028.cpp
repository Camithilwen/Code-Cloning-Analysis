#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int r = 0, g = 0, b = 0, ans = 1;
    for(int i=0; i<n; i++){
        if(a[i] == r && a[i] == g && a[i] == b){ ans *= 3; r += 1; }
        else if(a[i] == r && a[i] == g){ ans *= 2; r += 1; }
        else if(a[i] == g && a[i] == b){ ans *= 2; g += 1; }
        else if(a[i] == r) r += 1;
        else if(a[i] == g) g += 1;
        else if(a[i] == b) b += 1;
        else ans = 0;

        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}