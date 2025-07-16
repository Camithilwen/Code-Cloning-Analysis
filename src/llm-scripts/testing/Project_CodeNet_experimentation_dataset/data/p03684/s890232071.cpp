#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

class UnionFind
{
public:
    UnionFind(int n)
        : mN(n)
    {
        REP(i, n)
        {
            mNodeTbl.push_back(i);
            mRankTbl.push_back(0);
        }
    }

    int find(int x)
    {
        if (x == mNodeTbl[x])
            return x;
        return mNodeTbl[x] = find(mNodeTbl[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    void unit(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (mRankTbl[x] < mRankTbl[y])
        {
            mNodeTbl[x] = y;
        }
        else
        {
            mNodeTbl[y] = x;
            if (mRankTbl[x] == mRankTbl[y])
                mRankTbl[x]++;
        }
    }

private:
    int mN;
    vector<int> mNodeTbl;
    vector<int> mRankTbl;
};

struct grid
{
    pll g;
    int index;
};
  vector<grid> G,X,Y;

ll len(pll a)
{
    return std::min(abs(G[a.first].g.first - G[a.second].g.first), abs(G[a.first].g.second - G[a.second].g.second));
}

int main()
{
    ll N;
    cin >> N;
    UnionFind uf(N);
    G.resize(N);
    REP(i, N)
    {
        cin >> G[i].g.first >> G[i].g.second;
        G[i].index = i;
    }
    X=G;
    Y=G;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return len(a) > len(b); });
    sort(X.begin(),X.end(), [](grid a, grid b) { return a.g.first > b.g.first; });
    REP(i, N - 1)
    {
        q.push(pll(X[i].index, X[i + 1].index));
    }
    sort(Y.begin(),Y.end(), [](grid a, grid b) { return a.g.second > b.g.second; });
    REP(i, N - 1)
    {
        q.push(pll(Y[i].index, Y[i + 1].index));
    }

    ll s = 0;
    while (!q.empty())
    {
        pll t = q.top();
        q.pop();
        if (uf.same(t.first, t.second))
            continue;
        uf.unit(t.first, t.second);
        s += len(t);
    }
    cout << s << endl;
    return 0;
}