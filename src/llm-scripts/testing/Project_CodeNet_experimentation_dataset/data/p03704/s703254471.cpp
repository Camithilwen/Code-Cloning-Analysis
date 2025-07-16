#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int d;
ll ans = 0;
ll p[20];

ll Cal(int i , ll d , int len){
    if(i == len / 2)return (d == 0 ? ((len & 1) ? 10 : 1) : 0);
    ll tmp = p[len - i - 1] - p[i];
    ll tmp1 = d / tmp;
    ll ans = 0;
    if(tmp1 >= -9 && tmp1 <= 9)ans += Cal(i+1,d-tmp*tmp1,len) * (10 - abs(tmp1) - (i == 0));
    tmp1 += (d >= 0 ? 1 : -1);
    if(tmp1 >= -9 && tmp1 <= 9)ans += Cal(i+1,d-tmp*tmp1,len) * (10 - abs(tmp1) - (i == 0));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w  ",stdout);
    }
    p[0] = 1;
    for(int i = 1 ; i <= 19 ; ++i)p[i] = p[i - 1] * 10;
    int d;cin >> d;
    for(int i = 1 ; i <= 18 ; ++i)ans += Cal(0,d,i);
    cout << ans;
}
