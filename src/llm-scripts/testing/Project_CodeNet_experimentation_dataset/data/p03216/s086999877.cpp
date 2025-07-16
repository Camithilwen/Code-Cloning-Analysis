#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second
#define int long long

int n;
string s;
int q;
long long pr[1500000];
vector<pair<int, int> > keks;
long long prr[1500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i)
        pr[i] = pr[i - 1]; pr[i] += s[i] == 'M';
        if (s[i] == 'C') keks.push_back({i, pr[i]});
    }
    for (int i = 0; i < keks.size(); i++)
    {
        if (i) prr[i] = prr[i - 1];
        prr[i] += keks[i].second;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k = 0;
        cin >> k;
        long long ans = 0;
        int l = -1, l2 = -1;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'D')
            {
                while (l + 1 < keks.size() && keks[l + 1].first < j + k) l++;
                while (l2 + 1 < keks.size() && keks[l2 + 1].first < j) l2++;
                ans += prr[l] - (l2 >= 0 ? prr[l2] : 0) - (l - l2) * pr[j];
            }
        }
        cout << ans << "\n";
    }
}