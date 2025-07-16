#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define rep(i,x) for(ll i=0;i<x;++i)
#define rep1(i,x) for(ll i=1;i<=x;++i)
#define rrep(i,x) for(ll i=x-1;i>=0;--i)
#define rrep1(i,x) for(ll i=x;i>=1;--i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rev(a) reverse(all(a))

template<typename T> T get(){T a;cin >> a;return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9;
const ll linf = 1e18;

int main()
{
    int N; cin >> N;

    vi team(N), rnk(N);

    fill(all(team), 0); fill(all(rnk), 1);

    rep(i, (N*N-N)/2) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--;
        if (c > d) team[a]+=3;
        else if (d > c) team[b]+=3;
        else {team[a]++;team[b]++;}
    }

    rep(i, N) rep(j, N) {
        if (team[i] < team[j]) rnk[i]++;
    }

    rep(i, N) cout << rnk[i] << endl;
}