#include <bits/stdc++.h>
#define LL long long
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOD(i,a,b) for(int i=a; i>=b; i--)
#define pa pair<int,int>
#define fi first
#define se second
#define MOD xxx
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) ((n^(1<<(i-1))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
using namespace std;
const int N = 80+5;
const int P = 12800;
int m,n;
int A[N][N],B[N][N];
int F[N][N][N*N*4];
int tmp,ans(0);
int main()
{
    cin >> m >> n;
    FOR(i,1,m)
    FOR(j,1,n) cin >> A[i][j];
    FOR(i,1,m)
    FOR(j,1,n) cin >> B[i][j];
    tmp = A[1][1] - B[1][1];
    F[1][1][tmp +P] = F[1][1][-tmp +P] = 1;
    FOR(i,1,m)
    FOR(j,1,n)
    if(i+j!=2)
    {
        tmp = A[i][j] - B[i][j];
        FOR(k,0,2*P)
        if(F[i-1][j][k] || F[i][j-1][k])
        {
            F[i][j][k+tmp] = F[i][j][k-tmp] = 1;
        }
    }
    FOR(i,0,P)
    {
        if(F[m][n][i+P]==1)
        {
            ans = i;
            break;
        }
        if(F[m][n][i])
        ans = i-P;
    }
    cout << abs(ans);
	return 0;
}
