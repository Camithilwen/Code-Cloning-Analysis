/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxm 1000006
#define pii pair <int,int>
#define Task ""
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,gt[maxn << 1],ans,cur;
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    //freopen(Task".inp", "r",stdin);
    //freopens(Task".out", "w",stdout);
    cin >> n;
    n <<= 1;
    gt[0] = 1;
    FOR(i,1,n) gt[i] = (1ll*gt[i-1]*i) % maxc;
    ans = gt[n / 2];
    FOR(i,1,n)
    {
        int x;
        char c;
        cin >> c;
        x = (c == 'W');
        if (x)
        {
            if (cur & 1)
            {
                ++cur;
            }
            else
            {
                ans = (1ll*ans*cur) % maxc;
                --cur;
            }
        }
        else
        {
            if (cur & 1)
            {
                ans = (1ll*ans*cur) % maxc;
                --cur;
            }
            else
            {
                ++cur;
            }
        }
    }
    if (cur) ans = 0;
    cout << ans;
    return 0;
}
