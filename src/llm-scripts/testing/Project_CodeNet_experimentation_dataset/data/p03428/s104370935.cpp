#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

const double Pi = acos(-1.);
const int N = 110;
int n;
struct D{double x, y, f;} d[N], e[N];
double ans[N];

bool cmp(D a, D b) {return a.f < b.f;}

int main() {
	int i, j, m; D key;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lf%lf", &d[i].x, &d[i].y);
	rep(i, 1, n) {
		key = d[i];
		
		m = 0;
		rep(j, 1, n)
			if(i != j) {e[++m] = d[j]; e[m].f = atan2(e[m].y-key.y, e[m].x-key.x);}
		sort(e+1, e+m+1, cmp);
		rep(j, 1, m-1)
			if(e[j+1].f - e[j].f > Pi) ans[i] = (e[j+1].f - e[j].f - Pi) / Pi / 2.;
		if(e[1].f + Pi + Pi - e[m].f > Pi) ans[i] = (e[1].f + Pi - e[m].f) / Pi / 2.;
		printf("%.7lf\n", ans[i]);
	}
	return 0;
}