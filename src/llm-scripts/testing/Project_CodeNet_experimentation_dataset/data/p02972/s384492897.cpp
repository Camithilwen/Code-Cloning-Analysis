#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin>>N;
    int a[N+1];
    rep(i, 1, N+1) {
        cin>>a[i];
    }
    int b[N+1]={};
    // memset(b, -1, sizeof(int));
    for (int i=N;i>0;--i) {
        for (int j=2*i;j<=N;j+=i) {
            b[i]^=b[j];
        }
        b[i]^=a[i];
    }
    int ans=0;
    rep(i, 1, N+1) {
        if (b[i])++ans;
    }
    cout<<ans<<endl;
    if (ans) {
        rep(i, 1, N+1) {
            if (b[i])cout<<i<<' ';
        }
        cout<<endl;
    }

}
int main()
{
    func();
}