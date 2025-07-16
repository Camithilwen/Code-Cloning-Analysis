#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
string s;
int ans[MAXN];

bool wolo()
{
    for (int i = 1; i <= N + 1; i++)
    {
        int av = 0;
        if (s[i] == 'x') av = 1;
        ans[i+1] = (av + ans[i] + ans[i-1]) % 2;
        if (i + 1 >= N && ans[i+1] != ans[i+1-N]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> s;
    s += s;

    for (int i = 0; i < 4; i++)
    {
        ans[0] = i % 2;
        ans[1] = i / 2;

        if (wolo())
        {
            for (int j = 0; j < N; j++)
            {
                if (ans[j]) cout << 'W';
                else cout << 'S';
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}