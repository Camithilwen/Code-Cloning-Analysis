#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

int dp[12][9 * mx6], g, d, p[12], c[12];

int stt(int id, int S)
{
    if(id > d){
        if(S < g)
            return 1e7;
        return 0;
    }

    if(dp[id][S] != -1)
        return dp[id][S];

    int ans = INT_MAX;
    for(int i = 0; i < p[id]; i++){
        ans = min(ans, i + stt(id + 1, S + i * id * 100));
    }

    ans = min(ans, p[id] + stt(id + 1, S + id * 100 * p[id] + c[id]));

    return dp[id][S] = ans;
}

int main()
{
    mem(dp, -1);
    cin >> d >> g;

    for(int i = 1; i <= d; i++)
        cin >> p[i] >> c[i];

    cout << stt(1, 0) << '\n';
    return 0;
}
