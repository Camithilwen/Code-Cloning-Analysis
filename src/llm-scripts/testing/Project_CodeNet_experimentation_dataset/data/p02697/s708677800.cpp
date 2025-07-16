#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n,m;
    cin >> n >> m;
    int l = n-1,r = 0;
    vector<P> ans;
    vector<bool> a(n+1,false);
    for (int i = 0;i < n/2;++i) {
        ans.push_back(make_pair(l,r));
        a[l-r] = a[n-(l-r)] = true;
        l--;r++;
        if (a[l-r] || a[n-(l-r)] || l-r == n-l+r) {
            l--;
            while (l > r) {
                ans.push_back(make_pair(l,r));
                l--;r++;
            }
            break;
        }
    }
    for (int i = 0;i < m;++i) cout << ans[i].first+1 << " " << ans[i].second+1 << newl;
}