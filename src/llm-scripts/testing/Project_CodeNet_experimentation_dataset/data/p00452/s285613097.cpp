#include <cstdio>
#include <algorithm>
using namespace std;

int p[1010];
int sum[1002010];

int main(void){
	int n,m;

	while(scanf("%d%d",&n,&m) && (n||m)){
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		p[n++] = 0; //0ツ点ツづ個スツコツアツづーツ催ャツづゥ

		int size=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				sum[size++] = p[i] + p[j];
			}
		}
		sort(sum,sum+size);

		int ans = 0;

		for(int i=0;i<size;i++){
			int rem = m - sum[i];
			if(rem < 0) continue;
			int left = 0, right = size;

			while(left < right){
				int center = (left + right) / 2;
				if(rem > sum[center]){
					left = center + 1;
				}
				else if(rem < sum[center]){
					right = center;
				}
				else {
					break;
				}
			}

			ans = max(ans, sum[i] + sum[right-1]);
		}

		printf("%d\n",ans);
	}

	return 0;
}