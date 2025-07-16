#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int MOD = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;

int main()
{
    cin >> S;
    smatch ssmm;
    if(regex_search(S,ssmm,regex("^A[a-z]+C[a-z]+$")))
    {
        cout << "AC";
        return 0;
    }
    cout << "WA";

    return 0;
}