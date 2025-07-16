#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238


#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(i =0 ; i <n ;i++){
            cin >> v[i];
        }
        while(k--){
            vector<ll> v2(n + 1);
            for(i =0 ; i <n ;i++){
                ll lo, hi;
                lo = max(0LL, i - v[i]);
                hi = min(i + v[i], n - 1);
                v2[lo]++;
                v2[hi + 1]--;
            }
            for(i = 1 ;i < n; i++){
                v2[i] += v2[i - 1] ;
            }
            for(i =0 ;i < n; i++){
                v[i] = v2[i];
            }
            bool flag = true;
            for(i =0 ;i < n; i++){
                if(v[i] != n){
                    flag = false;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        for(i =0 ;i < n; i++){
            cout << v[i] <<" ";
        }
    }

    return 0;
}
