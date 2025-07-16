#include<iostream>
#include<string.h>
using namespace std;
int kingaku(void);
int saitan(void);
#define WHITE 0
#define GLAY 1
#define BLACK 2
#define INF 9999
int n;	//	??????????????±?????°
int m;	//	?§??????°
int p;	//	????????°
int q;	//	??°?????°
int minv;
int cost[101][101];
int Time[101][101];
int dd[101];
int main()
{
	int a,b,c,t,k,r;
	while(1){
		memset(cost,INF,sizeof(cost));
		memset(Time,INF,sizeof(Time));
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		for(int i=0;i<n;i++){
			cin >> a >> b >> c >>t;
			cost[a][b] = cost[b][a] = c;
			Time[a][b] = Time[b][a] = t;
		}
		cin >> k;
		for(int i=0;i<k;i++){
			cin >> p >> q >> r;
			if(r == 0)
				cout << kingaku() << endl;
			else if(r == 1)
				cout << saitan() << endl;
			//for(int i=1;i<=m;i++)
			//	cout << i << " " << dd[i] << endl;
		}
	}
	return 0;
}

int kingaku()
{
	int u;
	int color[101];
	memset(dd,INF,sizeof(dd));
	memset(color,WHITE,sizeof(color));
	dd[p] = 0;
	color[p] = GLAY;
	while(1){
		u = -1;
		minv = INF;
		for(int i=1;i<=m;i++){
			if(minv > dd[i] && color[i] != BLACK){
				minv = dd[i];
				u = i;
			}
		}
		if(u==-1) break;
		color[u] = BLACK;
		for(int i=1;i<=m;i++){
			if(cost[u][i] != INF && color[i] != BLACK){
				if(dd[i] > dd[u] + cost[u][i])	//
					     //1?§?     1?§???¨??\?????????????§?
					dd[i] = dd[u] + cost[u][i];
			}
		}
	}
	return dd[q];
}

int saitan()
{
	int u;
	int color[101];
	memset(dd,INF,sizeof(dd));
	memset(color,WHITE,sizeof(color));
	dd[p] = 0;
	color[p] = GLAY;
	while(1){
		u = -1;
		minv = INF;
		for(int i=1;i<=m;i++){
			if(minv > dd[i] && color[i] != BLACK){
				minv = dd[i];
				u = i;
			}
		}
		if(u==-1) break;
		color[u] = BLACK;
		for(int i=1;i<=m;i++){
			if(Time[u][i] != INF && color[i] != BLACK){
				if(dd[i] > dd[u] + Time[u][i])
					dd[i] = dd[u] + Time[u][i];
			}
		}
	}
	return dd[q];
}