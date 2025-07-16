#include <cstdio>
#include <cstring>
using namespace std;

int n, k;
int array[10];

int c[4];
bool use[10];
char str[10000][100];
int m;

int number[10000];
int p;

void Search(int i, int j)
{
	if (j == k){
		for (int l = 0; l < k; l++){
			char nstr[3];
			sprintf(nstr, "%d", c[l]);
			strcat(str[m], nstr);
		}
		
		int num;
		sscanf(str[m], "%d", &num);
//		printf("%d\n", num);

		bool f = false;
		for (int l = 0; l < p; l++){
			if (number[l] == num){
				f = true;
				break;
			}
		}
		
		if (!f){
			number[p] = num;
			p++;
		}
		
		m++;
		return;
	}
	
	if (i == n){
		return;
	}
	
	Search(i + 1, j);
	
	if (use[i]){
		return;
	}
	
	c[j] = array[i];
	
	use[i] = true;
	
	Search(0, j + 1);
	
	use[i] = false;
}

int main()
{
	while (scanf("%d %d", &n, &k), n + k){
		memset(array, 0, sizeof(array));
		memset(c, 0, sizeof(c));
		memset(use, 0, sizeof(use));
		memset(str, 0, sizeof(str));
		memset(number, 0, sizeof(number));
		m = 0;
		p = 0;
		
		for (int i = 0; i < n; i++){
			scanf("%d", &array[i]);
		}
		
		Search(0, 0);
		
		printf("%d\n", p);
	}
	
	return 0;
}