#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

int p[10];

int main(){
	for(int i = 0; i < 2; i++){
		int ans = 0;
		for(int j = 0; j < 10; j++) scanf("%d", &p[j]);
		sort(p,p+10,greater<int>());
		for(int j = 0; j < 3; j++) ans += p[j];
		if(i == 0) printf("%d", ans);
		else printf(" %d\n", ans);
	}
}