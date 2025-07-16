/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxn 200005
#define maxm 1000006
#define maxc 1000000007
#define pii pair <int,int>
#define Task ""
#define double long double
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
const double Pi = acos(-1);
using namespace std;
int n,t[55][55];
pii a[maxn];
long long ans;
int Get(int u,int v)
{
    if (!u || !v) return 0;
    int res = 0;
    while (u)
    {
        int temp = v;
        while (temp)
        {
            res += t[u][temp];
            temp -= temp & -temp;
        }
        u -= u & -u;
    }
    return res;
}
void Update(int u,int v,int val)
{
    while (u <= 50)
    {
        int temp = v;
        while (temp <= 50)
        {
            t[u][temp] += val;
            temp += temp & -temp;
        }
        u += u & -u;
    }
}
int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
    if(fopen(".inp", "r")) freopen(".inp", "r", stdin);
    //freopen(Task".inp", "r",stdin);
    //freopen(Task".out", "w",stdout);
    cin >> n;
    FOR(i,1,n)
    {
        double x;cin >> x;
        long long u = round(x * 1e9);
        while (u % 2 == 0)
        {
            ++a[i].F;
            u >>= 1;
        }
        while (u % 5 == 0)
        {
            ++a[i].S;
            u /= 5;
        }
    }
    FOR(i,1,n)
    {
        int need2 = max(1,18 - a[i].F + 1),
            need5 = max(1,18 - a[i].S + 1);
        ans += Get(50,50);
        ans -= Get(need2 - 1,50);
        ans -= Get(50,need5 - 1);
        ans += Get(need2 - 1,need5 - 1);
        Update(a[i].F + 1,a[i].S + 1, 1);
    }
    cout << ans;
    return 0;
}
