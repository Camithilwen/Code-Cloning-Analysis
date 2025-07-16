#include <iostream>
#include <limits.h>

using namespace std;

int m;

int dijkstra( const int data[101][101], int start, int end )
{
	int i,j,next,min;
	bool visited[101];
	int distance[101];

	for( i = 1;i <= 100;i++ ){
		visited[i] = false;
		distance[i] = INT_MAX;
	}

	distance[start] = 0; next = start;

	do{
		i = next; visited[i] = true; min = INT_MAX;
		for(j = 1;j <= m;j++){
			if(visited[j]) continue;
			if(data[i][j] < INT_MAX && distance[i] + data[i][j] < distance[j]) {
				distance[j] = distance[i] + data[i][j];
			}
			if( distance[j] < min ){
				min = distance[j]; next = j;
			}
		}
	} while( min < INT_MAX );

	return distance[end];
}


int main(int argc, char const* argv[])
{
	int n,weight[101][101][2];

	while( cin >> n >> m && n != 0 && m != 0 ){
		int a,b,c,d;
		for( int i = 0;i < 101;i++ ){
			for( int j = 0;j < 101;j++ ){
				weight[i][j][0] = INT_MAX;
				weight[i][j][1] = INT_MAX;
			}
		}

		for( int i = 0;i < n;i++ ){
			cin >> a >> b >> c >> d;
			weight[a][b][0] = c;
			weight[b][a][0] = c;
			weight[a][b][1] = d;
			weight[b][a][1] = d;
		}

		cin >> n;

		for( int i = 0;i < n;i++ ){
			int data[101][101];
			int p,q,r;
			cin >> p >> q >> r;
			for( int j = 1;j < 101;j++ ){
				for( int k = 1;k <101;k++ ) data[j][k] = weight[j][k][r];
			}
			cout << dijkstra( data, p, q ) << endl;
		}
	}


	return 0;

		
}