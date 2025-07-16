#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    int in = 1,res=0;
    while (in <b){

        in += a - 1;
        res += 1;


    }
    cout << res ;
    return 0;
}
