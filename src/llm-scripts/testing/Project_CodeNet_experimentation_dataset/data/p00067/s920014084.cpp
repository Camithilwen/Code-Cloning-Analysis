#include <cstdio>

using namespace std;

int main()
{
	char mp[15][15] = {0};
	int pi, pj;
	int cnt;
	while (scanf("%s", mp[1]) != EOF){
		cnt = 0;
		
		for (int i = 2; i <= 12; i++) scanf("%s", mp[i]);
		
		for (int i = 1; i <= 12; i++){
			for (int j = 0; j < 12; j++){
				if (mp[i][j] == '1'){
					if(mp[i-1][j] != '2') {
						cnt++;
					}
					while(mp[i][j] != '0' && j < 12){
						mp[i][j] = '2';
						pi = i;
						while (mp[++pi][j] == '1'){
							pj = j;
							while(mp[pi][pj] == '1'){
								mp[pi][pj] = '2';
								pj--;
							}
							pj = j;
							while(mp[pi][++pj] == '1'){
								mp[pi][pj] = '2';
							}
						}
						j++;
					}
				}
			}
		}
		
		printf("%d\n", cnt);
	}
}