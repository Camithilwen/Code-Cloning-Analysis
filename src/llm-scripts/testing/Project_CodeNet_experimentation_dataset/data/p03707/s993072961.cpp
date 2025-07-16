#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

//using namespace __gnu_pbds;
using namespace std ;

typedef pair<int, int> pi ;
//typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const i64 mod = 1000000007LL ;
#define INF 2000000000001LL
#define maxn 200005

/*
     *os.find_by_order(k) -> returns the k'th smallest element (indexing starts from 0)
      os.order_of_key(v)  -> returns how many elements are strictly smaller than v
*/

int Left[2002][2002] , Up[2002][2002] ;
int ones[2002][2002] ;
char s[2005][2005] ;

int main()
{
    int n , m , q ;

    scanf("%d %d %d",&n,&m,&q) ;

    for(int i=1 ; i<=n; i++) scanf("%s",s[i]+1) ;

    for(int i=1; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if( s[i][j]=='1' ) ones[i][j] = 1 ;
        }
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if( ones[i][j] == 1 && ones[i-1][j] == 1 ) Up[i][j] = 1 ;
            if( ones[i][j] == 1 && ones[i][j-1] == 1 ) Left[i][j] = 1 ;
        }
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            Left[i][j] += Left[i][j-1] ;
            Up[i][j] += Up[i][j-1] ;
        }
        for(int j=1 ; j<=m ; j++)
        {
            Left[i][j] += Left[i-1][j] ;
            Up[i][j] += Up[i-1][j] ;
        }
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m; j++) ones[i][j] = ones[i][j-1] + ones[i][j] ;
        for(int j=1 ; j<=m; j++) ones[i][j] += ones[i-1][j] ;
    }

    for(int i=1 ; i<=q ; i++)
    {
        int x1 , y1 , x2, y2 ;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2) ;

        int nodes = ones[x2][y2] - ones[x1-1][y2] - ones[x2][y1-1] + ones[x1-1][y1-1] ;
        int edgesHor = Left[x2][y2] - Left[x1-1][y2] - Left[x2][y1] + Left[x1-1][y1] ;
        int edgesVer = Up[x2][y2] - Up[x1][y2] - Up[x2][y1-1] + Up[x1][y1-1] ;

        printf("%d\n",nodes-edgesHor-edgesVer) ;
    }


    return 0 ;
}
