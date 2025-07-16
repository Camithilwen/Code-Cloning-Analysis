#include <bits/stdc++.h>
using namespace std;
int n,m,p1,p2,mn,mx;
int main() {
    cin>>n>>m; mx=1; mn=n;
    for (int i=0; i<m; i++) {
        cin>>p1>>p2;
        mx=max(mx,p1);
        mn=min(mn,p2);
    }
    cout<<max(0,mn-mx+1)<<'\n';
}