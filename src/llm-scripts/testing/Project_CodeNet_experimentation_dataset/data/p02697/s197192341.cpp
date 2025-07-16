//
// Created on 2020/05/02.
//


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
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>ans;
    if(n % 2 == 1){
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back({i,(n+1)-i});
        }
        for (int j = 0; j < m; ++j) {
            cout<<ans[j].first<<" "<<ans[j].second<<endl;
        }
    }else{
        int r,l;
        r = 1;
        l = n -1;
        bool frag = false;
        while(r < l){
            if(l-r <= n / 2 && !frag){
                r ++;
                frag = true;
                continue;
            }
            ans.push_back({r,l});
            r++;
            l--;
        }

        for (int j = 0; j < m; ++j) {
            cout<<ans[j].first<<" "<<ans[j].second<<endl;
        }
    }

    return 0;
}
