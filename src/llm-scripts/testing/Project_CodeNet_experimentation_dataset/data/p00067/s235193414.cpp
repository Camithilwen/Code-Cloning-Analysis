#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int par[16][16];
int rank[16][16];
char map[16][16];
int cnt;

void init();
void unite(int y1, int x1, int y2, int x2);
int find(int y, int x);

int main()
{
	while (scanf("%s", &map[1][1]) != EOF){
		for (int i = 2; i <= 12; i++) scanf("%s", &map[i][1]);
		init();
		for (int i = 1; i <= 12; i++){
			for (int j = 1; j <= 12; j++){
				if (map[i][j] == '1'){
					cnt++;
					unite(i, j, i - 1, j);
					unite(i, j, i + 1, j);
					unite(i, j, i, j - 1);
					unite(i, j, i, j + 1);
				}
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}

void init()
{
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			par[i][j] = i * 16 + j;
			rank[i][j] = 1;
		}
	}
	cnt = 0;
}

void unite(int y1, int x1, int y2, int x2)
{
	if (map[y2][x2] == '1' && find(y1, x1) != find(y2, x2)){
		if (rank[y1][x1] < rank[y2][x2]){
			par[y1][x1] = y2 * 16 + x2;
			rank[y1][x1]++;
		}
		else {
			par[y2][x2] = y1 * 16 + x1;
			rank[y2][x1]++;
		}
		cnt--;
	}
}

int find(int y, int x)
{
	if (par[y][x] != y * 16 + x){
		par[y][x] = find(par[y][x] / 16, par[y][x] % 16);
	}
	return par[y][x];
}