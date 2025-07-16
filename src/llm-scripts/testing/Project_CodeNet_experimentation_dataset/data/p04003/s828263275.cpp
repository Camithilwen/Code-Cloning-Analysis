//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define N 100005
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1 == p2)?EOF:*p1++)
using namespace std ;
//char buf[(1 << 22)] , *p1 = buf , *p2 = buf ;
inline int read ()
{
    char c = getchar () ; int x = 0 , f = 1 ;
    while (c < '0' || c > '9') { if (c == '-') f = -1 ; c = getchar () ; }
    while (c >= '0' && c <= '9'){ x = x * 10 + c - '0' ; c = getchar () ; }
    return x * f ;
}
map <int , int> mp[N << 3] ; //mp[u][w]:u属性为w的虚点编号
vector <pair <int , int> > edge[N << 3] ;
int dis[N << 3] , vis[N << 3] , n , m ;
queue <int> q ;
void spfa (int s)
{
    int tim = 0 ;
    for (int i = 0 ; i <= (N << 3) - 5 ; i ++) dis[i] = 1e9 ;
	// fill (dis , dis + (N << 2) , 1e9) ;
	dis[s] = 0 ;
	vis[s] = 1 ;
	q.push (s) ;
	while (! q.empty ())
	{
        // printf ("The %d time\n" , ++ tim) ;
		int x = q.front () ;
		q.pop () ;
		for (int i = 0 ; i < edge[x].size () ; i ++)
		{
			int y = edge[x][i].first ;
			if (dis[y] > dis[x] + edge[x][i].second)
			{
				dis[y] = dis[x] + edge[x][i].second ;
				if (! vis[y])
				{
					vis[y] = 1 ;
					q.push (y) ;
				}
			}
		}
        vis[x] = 0 ;
	}
}
int main ()
{
//    freopen (".in" , "r" , stdin) ; freopen (".out" , "w" , stdout) ;
	n = read () , m = read () ;
    int tot = n ;
	for (int i = 1 ; i <= m ; i ++)
	{
		int u = read () , v = read () , w = read () ;
        if (! mp[u].count (w))
        {
            mp[u][w] = ++ tot ;
            edge[u].push_back (make_pair (tot , 1)) ;
            edge[tot].push_back (make_pair (u , 1)) ;
        }
        if (! mp[v].count (w))
        {
            mp[v][w] = ++ tot ;
            edge[v].push_back (make_pair (tot , 1)) ;
            edge[tot].push_back (make_pair (v , 1)) ;
        }
        edge[mp[u][w]].push_back (make_pair (mp[v][w] , 0)) ;
        edge[mp[v][w]].push_back (make_pair (mp[u][w] , 0)) ;
    }
    spfa (1) ;
    if (dis[n] == 1e9) return puts ("-1") , 0 ;
    cout << dis[n] / 2 ;
}
