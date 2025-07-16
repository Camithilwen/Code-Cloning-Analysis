#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 300000

int n, pm, pe, pj;

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			return 0;

		while(n-- > 0) {
			scanf("%d %d %d", &pm, &pe, &pj);
			if(max(pm, max(pe, pj)) == 100 || pm + pe >= 180 || pm + pe + pj >= 240)
				puts("A");
			else if(pm + pe + pj >= 210 || pm + pe + pj >= 150 && max(pm, pe) >= 80)
				puts("B");
			else
				puts("C");
		}
	}
}