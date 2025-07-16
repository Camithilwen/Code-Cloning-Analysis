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

vector<long long> enum_divisors(long long N)
{
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    ll N, M;
    cin >> N >> M;
    ll ans = 1;
    auto div = enum_divisors(M);

    for (int i = M / N; i >= 1;i--)
    {
        for (int j = 0; j < div.size();j++)
        {
            if(div[j] == i){
                ans = i;
                break;
            }
            //cout << i << " " <<div[j] << endl;
        }
        if (ans != 1)
        {
            break;
        }
    }
    cout << ans << endl;
}
