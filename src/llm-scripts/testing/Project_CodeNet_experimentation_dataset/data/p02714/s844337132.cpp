#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, r = 0, b = 0, g = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') r++;
        else if (s[i] == 'B') b++;
        else g++;
    }

    long long ans = r * g * b;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j]) continue;

            int k = 2 * j - i;
            if (k >= n) break;
            if(s[k]!=s[i]&&s[k]!=s[j]) --ans;
        }
    }

    cout << ans << endl;
}