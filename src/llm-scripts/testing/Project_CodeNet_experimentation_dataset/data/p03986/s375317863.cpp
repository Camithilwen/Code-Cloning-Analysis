#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string x;
    cin >> x;
    int stack = 0, puyo = 0;
    rep(i, x.length())
    {
        if (x[i] == 'S')
            stack++;
        else if (stack)
        {
            stack--;
            puyo++;
        }
    }
    cout << x.length() - 2 * puyo << endl;
}