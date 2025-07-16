#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    vector<int> a(4);
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }
    cin >> m >> n;
    sort(a.rbegin(), a.rend());
    int ans = a[0] + a[1] + a[2] + max(m,n);
    cout << ans << endl;
    return 0;
}
