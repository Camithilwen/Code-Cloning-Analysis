#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m,q;cin>>n>>m>>q;
    int a[n+1][n+1]{};
    for (int i=0;i<m;i++) {
        int b,c;cin>>b>>c;
        a[b][c]++;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]+=a[i][j-1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]+=a[i-1][j];
    for (int i=0;i<q;i++) {
        int b,c;cin>>b>>c;
        cout<<a[c][c]-a[c][b-1]-a[b-1][c]+a[b-1][b-1]<<endl;
    }
    return 0;
}