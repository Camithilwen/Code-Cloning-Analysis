#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
 
const int oo=1000000000;
 
int n,m;
int f[1<<15][16][16];
int g[16][16];
 
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		memset(g,255,sizeof(g));
		REP(i,m)
		{
			int x,y,z;
			cin>>x>>y>>z;
			--x;
			--y;
			g[x][y]=g[y][x]=z;
		}
		REP(set,two(n))
		{
			REP(x,n) REP(y,n) f[set][x][y]=oo;
			if (!contain(set,0)) continue;
			if (contain(set,n-1) && set!=two(n)-1) continue;
			REP(x,n) f[set][x][x]=0;
			for (int set1=set-1;set1>0;set1=((set1-1)&set))
			{
				if (!contain(set1,0)) continue;
				int set2=(set^set1);
				int base=0;
				REP(x,n) if (contain(set1,x)) REP(y,n) if (contain(set2,y) && g[x][y]>=0) base+=g[x][y];
				REP(x,n) if (contain(set1,x)) REP(y,n) if (contain(set1,y)) REP(z,n) if (contain(set2,z) && g[y][z]>=0)
				{
					ckmin(f[set][x][z],base+f[set1][x][y]-g[y][z]);
				}
			}
		}
		printf("%d\n",f[two(n)-1][0][n-1]);
#ifndef _MSC_VER
		system("pause");
#endif
	}
	return 0;
}