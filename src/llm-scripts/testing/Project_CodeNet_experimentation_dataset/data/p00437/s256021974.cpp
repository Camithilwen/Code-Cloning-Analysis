#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	while(true){
		int a, b, c, N, i, j, t1, t2, t3, r;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0) return 0;
		scanf("%d", &N);

		vector< vector<int> > results;
		vector<int> ans(a+b+c+1, 2);

		for(i = 0;i < N;++i){
			vector<int> re;
			scanf("%d %d %d %d", &t1, &t2, &t3, &r);
			re.push_back(t1);re.push_back(t2);re.push_back(t3);re.push_back(r);
			results.push_back(re);

			if(r == 1){
				ans[t1] = 1;ans[t2] = 1;ans[t3] = 1;
			}
		}

		for(i = 0;i < N;++i){
			vector<int> re = results[i];
			if(re[3] == 0){
				if(ans[re[0]] == 1 && ans[re[1]] == 1){
					ans[re[2]] = 0;
				}else if(ans[re[1]] == 1 && ans[re[2]] == 1){
					ans[re[0]] = 0;
				}else if(ans[re[2]] == 1 && ans[re[0]] == 1){
					ans[re[1]] = 0;
				}
			}	
		}

		for(i = 1;i < a+b+c+1;++i) printf("%d\n", ans[i]);
	}
}
