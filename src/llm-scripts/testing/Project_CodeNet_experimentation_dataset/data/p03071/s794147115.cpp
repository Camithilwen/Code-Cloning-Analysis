#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b;
    cin >> a >> b;
    if(a == b) cout << a + b << endl;
    else if(a > b) cout << a*2-1 << endl;
    else cout <<b*2-1 << endl;
    return 0;
}