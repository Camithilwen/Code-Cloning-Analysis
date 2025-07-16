#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> l(2*n);
    for(int i=0; i<2*n; i++){
        cin >> l[i];
    }
    sort(l.begin(),l.end());

    long long int ans = 0;
    for(int i=0; i<n; i++){
        ans += l[2*i];
    }
    cout << ans << endl;
    return 0;
}