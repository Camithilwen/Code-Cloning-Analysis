#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    ll ans = 0;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    for (int i = 0; i < N;i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    for (int i = 0; i < N;i++)
    {
        auto itA = lower_bound(A.begin(),A.end(),B[i]);
        auto itC = upper_bound(C.begin(), C.end(),B[i]);
        ll a = itA - A.begin();
        ll b = C.end() - itC;
        //cout << a <<" " << b << endl;
        ans += a * b;
    }
    cout << ans << endl;
}
