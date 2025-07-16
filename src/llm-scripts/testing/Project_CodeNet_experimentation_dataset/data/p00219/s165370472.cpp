#include <cstdio>

using namespace std;

int main()
{
	int n;
	
	while (scanf("%d", &n), n != 0){
		int ice[10] = {0};
		int ice_n;
		for (int i = 0; i < n; i++){
			scanf("%d", &ice_n);
			ice[ice_n]++;
		}
		
		for (int i = 0; i < 10; i++){
			if (ice[i] == 0){
				puts("-");
			}
			else {
				while (ice[i]-- != 0){
					printf("*");
				}
				puts("");
			}
		}
	}
}