#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double dlb;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll, pair<ll,ll> > iii;

const int kn = 2e5 + 5;
const ll mod = 1e9 + 7;

#define x first
#define y second
#define _it iterator
#define pb push_back
#define pf push_front
#define ms(val,a) memset(a,val,sizeof(a))
#define ff(i,n) for(int i=1;i<=n;i++)
#define _ff(i,n) for(int i=n;i>=1;i--)
#define f(i,a,b) for(int i = a; i <=b; i++)
#define _f(i,a,b) for(int i = b; i>=a;i--)
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n, par[kn];
ll ans = 0;

struct data{
	int x, y;
	int id;
};

bool option(data cac, data lon)
{
	if(cac.x != lon.x) return cac.x < lon.x;
	return cac.y < lon.y;
}

data a[2][kn];

int Find(int i)
{
	if(par[i] == i) return i;
	return par[i] = Find(par[i]);
}

void dj(int i, int j, int cost)
{
	int pi = Find(i), pj = Find(j);
	if(pi == pj) return;
	par[pi] = pj;
	ans += cost;
}

int la[2][kn], ra[2][kn];

set< iii > pq;

int main() {
	//freopen("a.inp","r",stdin);
	//freopen("a.out","w",stdout);
	cin >> n;
	ff(i,n) par[i] = i;
	ff(i,n)
	{
		cin >> a[0][i].x >> a[0][i].y;
		a[1][i].x = a[0][i].y; a[1][i].y = a[0][i].x;
		a[0][i].id = a[1][i].id = i;
		la[0][i] = la[1][i] = i-1;
		ra[0][i]=ra[1][i] = i+1;
	}
	la[0][1] = la[1][1] = -1;
	ra[0][n] = ra[1][n] = -1;
	sort(a[0]+1,a[0]+n+1,option);
	sort(a[1]+1,a[1]+n+1,option);
	for(int i = 2; i<=n; i++)
	{
		pq.insert(iii(a[0][i].x - a[0][i-1].x, ii(i,0)));
		pq.insert(iii(a[1][i].x - a[1][i-1].x, ii(i,1))); // 0 la day 1, 1 la day 2
	}
	while(pq.size())
	{
		iii tmp = *pq.begin();
		pq.erase(pq.begin());
		dj(a[tmp.y.y][tmp.y.x].id, a[tmp.y.y][tmp.y.x-1].id, a[tmp.y.y][tmp.y.x].x - a[tmp.y.y][tmp.y.x-1].x);
	}
	cout << ans;
}
//hahahahahahahahahhahahahahahaahahahahhahahahahahahah