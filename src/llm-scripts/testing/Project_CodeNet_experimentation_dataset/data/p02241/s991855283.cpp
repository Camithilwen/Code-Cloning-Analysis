#include<iostream>
using namespace std;
static const int INF = 0x7fffffff;
static const int MAXN = 101;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[MAXN][MAXN];

int prim()
{
	int node, minn;  //记录当前状态权值最小的边和对应的节点
	int d[MAXN], p[MAXN], color[MAXN]; //最小边权，父节点，访问状态
	/*初始化*/
	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
		p[i] = -1;
		color[i] = WHITE; 
	}
	d[0] = 0;  //初始节点加入MST
	while (true)
	{
		node = -1;
		minn = INF;
		for (int i = 0; i < n; i++)
		{
			if (d[i] < minn && color[i] != BLACK)
			{
				minn = d[i];
				node = i;
			}
		}
		if (node == -1)	break; //图遍历完毕，没有可以新加入MST的节点
		color[node] = BLACK;   //把新节点加入MST

		/*更新状态*/
		for (int i = 0; i < n; i++) 
		{
			if (color[i] != BLACK && M[node][i] < INF)
			{
				if (d[i] > M[node][i])
				{
					d[i] = M[node][i];
					p[i] = node;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] != -1)	sum += M[i][p[i]];  //求MST每条边的权和
	}
	return sum;
}

int main()
{
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			M[i][j] = (tmp == -1 ) ? INF : tmp;
		}
	}
	cout << prim() <<endl;
    return 0;
}


