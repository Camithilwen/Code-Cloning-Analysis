#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int main()
{
    // que[R] = {L, index_of_query};
    // um is map such that um[element] = last index the element was seen
    // s - a set that contains the last index as mentioned above
    // code assumes 0 indexed
    // complexity - O(n*log(n))
  
    unordered_map<int, int>um;
    pbds s;
    int n; cin >> n;
     int q; cin >> q;
    vector<int>a(n);
    for (auto &it : a)
        cin >> it;
  
    vector<int>ans(q);
    vector<vector<pair<int, int>>>que(n);
    for (int i = 0; i < q; i++)
    {
        int L, R; cin >> L >> R;
        L --;
        R--;
        que[R].push_back({L, i});
    }
    for (int i = 0; i < n; i++)
    {
        if (um.count(a[i]))
            s.erase(um[a[i]]);
        um[a[i]] = i;
        s.insert(i);
        for (auto it : que[i])
            ans[it.second] = s.size() - s.order_of_key(it.first);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
    return 0;
}