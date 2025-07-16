#include<iostream>
#include<vector>
#include<algorithm>

const int INF = 1<<25;

using namespace std;

int main()
{
	int n,m,i,j;
	int cost[101][101],time[101][101];
	
	for(;;)
	{
		cin >> n >> m ;
		if(n==0 && m==0)
			break;
		
		for(i=0;i<m+1;i++)
		{
			for(j=0;j<m+1;j++)
			{
				if(i!=j)
					cost[i][j]=time[i][j]=INF;
				else
					cost[i][j]=time[i][j]=0;
			}
		}
		
		for(i=0;i<n;i++)
		{
			int a,b,co,ti;
			cin >> a >> b >> co >> ti ;
			cost[a][b]=cost[b][a]=co;
			time[a][b]=time[b][a]=ti;
		}
		
		int inp;
		cin >> inp ;
		
		for(int k=0;k<m+1;k++)
		{
			for(i=0;i<m+1;i++)
			{
				for(j=0;j<m+1;j++)
				{
					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
					time[i][j]=min(time[i][j],time[i][k]+time[k][j]);
				}
			}
		}
		
		for(i=0;i<inp;i++)
		{
			int st,en,se;
			cin >> st >> en >> se ;
			
			if(se==0)
				cout << cost[st][en] << endl;
			else
				cout << time[st][en] << endl;
		}
	}
}