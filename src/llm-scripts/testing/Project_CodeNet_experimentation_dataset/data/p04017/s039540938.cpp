#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;
int pa[100005][18];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto &i : v) {
        cin >> i;
    }
    int  k;
    cin >> k;
    for (int i = 0 ; i < n ; i++) {
        int l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (v[mid] - v[i] <= k) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        pa[i][0] = l;
    }
    for (int i = 1 ; i < 18 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            pa[j][i] = pa[pa[j][i - 1]][i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x , y;
        cin >> x >> y;
        x--, y--;
        if (x > y) {
            swap(x, y);
        }
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            int tx = x;
            for (int i = 0 ; i < 18 ; i++) {
                if (mid & (1<<i)) {
                    tx = pa[tx][i];
                }
            }
            if (tx >= y) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << '\n';
    }
}
