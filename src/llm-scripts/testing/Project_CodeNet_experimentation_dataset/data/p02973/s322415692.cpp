#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double

const int MOD = int(1e9+7);
const int oo  = int(1e9 + 20);
const ll lloo  = (ll)(1e18 + 10);


template <typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
    int NEUTRAL;
    int n;
    vector<int> tree;
    F func;
public:
    
    SegmentTree(vector<int> values, int neutral, const F& f) : func(f) {
        NEUTRAL = neutral;
        
        n = values.size();
        tree.resize(n*2);
        // Build
        for (int i=0; i < n; i++){
            tree[n+i] = values[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = func(tree[i*2], tree[i*2+1]);
        }
    }
    
    void update(int index, int value) {
        tree[index+n] = value;
        index = index + n;
        for (int i = index; i > 1; i >>= 1){
            tree[i/2] = func(tree[i], tree[i^1]);
        }
    }
    
    int query(int l, int r) {
        int ans = NEUTRAL;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                ans = func(ans, tree[l++]);
            }
            if (r&1) {
                ans = func(ans, tree[--r]);
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    n++;
    vector<int> val(n);
    for(int i = 1; i < n; ++i) {
        cin >> val[i];
    }
    
    SegmentTree<int> st(val, -oo, [&](int x, int y) -> int {return max(x, y);});
    
    vector<bool> visited(n, false);
    int colors = 0;
    int last;
    for(int i = 1; i < n; ++i) {
        if(!visited[i]) {
            colors++;
            last = val[i];
            visited[i] = true;
            st.update(i, -oo);
            
            if(st.query(i+1, n) <= last) continue;
            
            for(int j = i + 1; j < n; ++j) {
                if(!visited[j] && last < val[j]) {
                    last = val[j];
                    visited[j] = true;
                    st.update(j, -oo);
                    if(st.query(j+1, n) <= last) break;
                }
            }
        }
    }
    cout << colors << endl;

    return 0;
}
