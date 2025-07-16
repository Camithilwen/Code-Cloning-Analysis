#include <stdio.h>

char str[16][16];

/*
void erase(int x, int y)
{
	if (x < 0 || x > 11 || y < 0 || y > 11) return;
	if (str[y][x] == '0') return;
	
	str[y][x] = '0';
	
	erase(x + 1, y);
	erase(x, y + 1);
	erase(x - 1, y);
	erase(x, y - 1);
}
*/

void is(int i, int j)
{
	int n;
	int k;
	
	str[i][j] = '0';
	
	k = 1;
	for (n = 0; n < 2; n++){
		if (str[i + k][j] == '1' && i + k >= 0 && i + k < 12){
			is(i + k, j);
		}
		if (str[i][j + k] == '1' && j + k >= 0 && j + k < 12){
			is(i, j + k);
		}
		k = -1;
	}
}

int main(void)
{
	int i, j;
	int ans;
	int a;
//	int case_ = 0;
	 
	while (1){
//		if (case_) fgets(str[0], 16, stdin);
//		case_++;
		ans = 0;
		for (i = 0; i < 12; i++){
			if (fgets(str[i], 16, stdin) == NULL){
				return (0);
			}
		}
		for (i = 0; i < 12; i++){
			for (j = 0; j < 12; j++){
				if (str[i][j] == '1'){
					is(i, j);
					str[i][j] = '1';
					ans++;
				}
			}
		}
		printf("%d\n", ans);
		if (fgets(str[0], 16, stdin) == NULL) return(0);
	}
}