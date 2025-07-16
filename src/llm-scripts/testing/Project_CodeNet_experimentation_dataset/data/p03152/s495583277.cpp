#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;

int main() {
    ll h, w, a;
    cin >> h >> w;

    vector<Pii> nums(h*w+1, {-1, -1});
    bool ok = true;
    for(int i=0;i<h;++i) {
        cin >> a;
        if(nums[a].first != -1) ok = false;
        nums[a].first = i;
    }
    for(int i=0;i<w;++i) {
        cin >> a;
        if(nums[a].second != -1) ok = false;
        nums[a].second = i;
    }

    if(!ok) {
        cout << 0 << endl;
        return 0;
    }

    int used_line[h], used_row[w];
    ll line_cnt = 0, row_cnt = 0;
    fill(used_line, used_line+h, 0);
    fill(used_row, used_row+w, 0);

    ll ans = 1LL;
    for(ll i=h*w;i>=1;--i) {
        // cerr << i << ": " << nums[i].first << ", " << nums[i].second  << "\t";
        if(nums[i].first != -1) {
            ++used_line[nums[i].first];
            if(used_line[nums[i].first] == 1) {
                ++line_cnt;
            }
        }
        if(nums[i].second != -1) {
            ++used_row[nums[i].second];
            if(used_row[nums[i].second] == 1) {
                ++row_cnt;
            }
        }
        if(nums[i].first == -1 && nums[i].second == -1) {
            ans *= ((row_cnt*line_cnt) - (h*w - i));
        } else if(nums[i].first == -1) {
            ans *= line_cnt;
        } else if(nums[i].second == -1) {
            ans *= row_cnt;
        }
        ans %= MOD;

        if(ans <= 0) {
            ans = 0;
            break;
        }
    }

    cout << ans << endl;

    return 0;    
}

    