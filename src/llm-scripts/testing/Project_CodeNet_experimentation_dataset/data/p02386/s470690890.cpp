#include<cstdio>

int main(){
	int n,x;
	scanf("%d", &n);
	int dice[n][6];
	int tmp[6];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			scanf("%d", &dice[i][j]);
		}
	}

	int pt[5][6] = {	{5,1,3,4,6,2}, 
				 	{0,0,0,0,0,0},
					{4,2,1,6,5,3},
					{2,6,3,4,1,5},
					{3,2,6,1,5,4}};
	int t[24] = {0,0,0,2,0,0,0,2,0,0,0,4,0,0,0,4,0,0,0,2,0,0,0,0};

	for(int a = 0; a < n; a++){
		for(int b = a + 1; b < n; b++){
			for(int i = 0; i < 24 ; i++){
				int c = 0;
				while(!(dice[a][c] - dice[b][c])){
					c++;
					if(c == 6){
						printf("No\n");
						return 0;
					}
				}

				for(int j = 0; j < 6; j++){
					tmp[j] = dice[a][j];
				}
				for(int j = 0; j < 6; j++){
					x = pt[t[i]][j];
					dice[a][j] = tmp[x - 1];
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
}