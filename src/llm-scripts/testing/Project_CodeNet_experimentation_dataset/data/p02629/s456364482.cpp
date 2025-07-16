#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string res;
    while (n>0){
        int i = (n-1) % 26;
        char c = 'a' + i;

        res = c + res;

        n = (n-1) / 26;
    }cout << res;
    return 0;
}
