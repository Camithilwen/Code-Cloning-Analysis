#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n,num;
	while (scanf("%d",&n)&&n!=0) {
		vector<int> ice(10,0);
		for (int i=0; i<n; i++) {
			scanf("%d",&num);
			ice[num]++;
		}
		for (int i=0; i<10; i++) {
			if (ice[i]==0) {
				printf("-");
			} else {
				for (int j=0; j<ice[i]; j++) printf("*");
			}
			printf("\n");
		}
	}
}