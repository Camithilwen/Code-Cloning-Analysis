#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <ctime>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 999999999

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long int ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int const MOD = 1000000007;

int main() {
    int l[11]; l[0] = 0;
    int v1, v2;
    while(cin >> l[1]) {
        int sum = l[1];
        rep(i,2,11) {scanf(",%d", &l[i]); sum += l[i]; l[i] += l[i-1];}
        scanf(",%d,%d", &v1, &v2);

        double r = (double)sum / (v1 + v2);
        double dist = r * v1;
        rep(i,0,11) {
            if(dist <= l[i]) {cout << i << endl; break;}
        }
    }
    return 0;
}