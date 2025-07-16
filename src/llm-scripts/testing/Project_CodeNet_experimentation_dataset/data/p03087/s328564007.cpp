#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n,q; cin >> n >> q;
    string s; cin >> s;
    vector<int> l(q),r(q);
    for(int i = 0;i < q;i ++) cin >> l.at(i) >> r.at(i);

    for(int i = 0;i < q;i ++){
        l.at(i) --;
        r.at(i) --;
    }

    vector<int> ans(n);
    for(int i = 1;i < n;i ++){
        ans.at(i) = ans.at(i-1);
        if(s.at(i-1) == 'A' && s.at(i) == 'C') ans.at(i) ++;
    }

    for(int i = 0;i < q;i ++){
        cout << ans.at(r.at(i)) - ans.at(l.at(i)) << endl;
    }
}