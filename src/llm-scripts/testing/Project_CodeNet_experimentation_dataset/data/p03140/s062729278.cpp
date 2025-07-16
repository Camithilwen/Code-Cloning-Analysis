#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(void)
{
    int n, cnt=0;
    string a,b,c;
    cin >> n >> a >> b >> c;
    rep(i,n) cnt += set<char>({a[i], b[i], c[i]}).size() - 1;
    cout << cnt << endl;
    return 0;
}