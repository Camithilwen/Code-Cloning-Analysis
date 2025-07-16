#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int) 1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = [", __print(x)
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)

int n;
int a[51];

int f(int k)
{
    int ans = 0;
    for(int A = 0; A <= n; A++) {
        for(int B = 0; B <= n; B++) {
            if(A+B > k || A+B > n) continue;
            int sum = 0;
            vector<int> v;
            for(int i = 0; i < A; i++) {
                v.push_back(a[i]);
                sum += a[i];
            }
            for(int i = n-1; i >= n - B; i--) {
                v.push_back(a[i]);
                sum += a[i];
            }
            sort(v.rbegin(), v.rend());
            ans = max(ans, sum);
            for(int i = 0; i < k-A-B && v.size(); i++) {
                sum -= v.back();
                ans = max(ans, sum);
                v.pop_back();
            }
        }
    }
    return ans;
}

int main()
{
    int k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, f(i));
    }
    printf("%d\n", ans);
}
