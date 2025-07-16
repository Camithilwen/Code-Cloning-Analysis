#include <cstdio>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int x[6];

int main(){
	rep(i, 6){
		scanf("%d", &x[i]);
	}

	int s = 0;
	rep(i, 6){
		s += x[i];
	}
	printf("%d\n", s - *min_element(x, x + 4) - min(x[4], x[5]));
	return 0;
}