#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    string sa, sb, sc; cin >> sa >> sb >> sc;
    char nx = 'a';
    while (true) {
        if (nx == 'a') {
            if (sa.size() == 0) {
                cout << "A" << endl;
                return 0;
            }
            nx = sa[0];
            sa = sa.substr(1, sa.size()-1);
        } else if (nx == 'b') {
            if (sb.size() == 0) {
                cout << "B" << endl;
                return 0;
            }
            nx = sb[0];
            sb = sb.substr(1, sb.size()-1);
        } else {
            if (sc.size() == 0) {
                cout << "C" << endl;
                return 0;
            }
            nx = sc[0];
            sc = sc.substr(1, sc.size()-1);
        }
    }
    return 0;
}