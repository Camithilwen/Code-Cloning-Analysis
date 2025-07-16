#include <bits/stdc++.h>  

const int INF =1e9;
const int MOD =1e9+7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] ={ 1, 0, -1, 0 };
int dy[4] ={ 0, 1, 0, -1 };

int main()
{
int n,r;
cin>>n>>r;
cout<<r+(10-min(10,n))*100<<endl;
}