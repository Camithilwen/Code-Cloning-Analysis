#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> a,q;
    int b;
    for(int i=0;i<4;i++){
        cin >> b;
        a.push_back(b);
    }
    for(int i=0;i<2;i++){
        cin >> b;
        q.push_back(b);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(q.begin(),q.end(),greater<int>());
    int ans=0;
    for(int i=0;i<3;i++){
        ans+=a[i];
    }
    ans+=q[0];
    cout << ans << endl;

    return 0;
}
