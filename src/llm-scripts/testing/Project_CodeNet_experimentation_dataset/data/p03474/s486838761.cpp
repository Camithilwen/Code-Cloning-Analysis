#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ldouble = long double;
 
const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;

string res;

int main()
{
    ll a, b;
    string s;
    cin >> a >> b >> s;

    res = "Yes";
    for (int i = 0; i < s.length(); i++)
    {
        if (i == a)
        {
            if (s[i] != '-')
            {        
                res = "No";
            }
        }
        else
        {
            if (!('0' <= s[i] && s[i] <= '9'))
            {
                res = "No";
            }
        }
    }
    println(res);
}