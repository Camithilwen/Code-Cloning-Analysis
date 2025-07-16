#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int p[3], r;
};

int main()
{
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c), a){
		int n;
		scanf("%d", &n);
		vector<int> state(a+b+c, 2);
		vector<Data> d(n);
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<3; ++j){
				scanf("%d", &d[i].p[j]);
				d[i].p[j]--;
			}
			scanf("%d", &d[i].r);
			
			if(d[i].r == 1){
				for(int j=0; j<3; ++j)
					state[d[i].p[j]] = 1;
			}
		}
		
		for(int i=0; i<n; ++i){
			if(d[i].r == 0){
				for(int j=0; j<3; ++j){
					if(state[d[i].p[j]]==1 && state[d[i].p[(j+1)%3]]==1 && state[d[i].p[(j+2)%3]]==2){
						state[d[i].p[(j+2)%3]] = 0;
						break;
					}
				}
			}
		}
		
		for(int i=0; i<a+b+c; ++i)
			printf("%d\n", state[i]);
	}
	
	return 0;
}