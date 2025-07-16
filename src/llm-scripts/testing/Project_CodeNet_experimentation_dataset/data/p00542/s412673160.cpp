#include<algorithm>
#include<functional>
#include<cstdio>
using namespace std;

int main(void){
	int sci[4], soc[2];
	scanf("%d%d%d%d%d%d", sci+0, sci+1, sci+2, sci+3, soc+0, soc+1);
	sort(sci, sci+4, greater<int>());
	printf("%d\n", sci[0]+sci[1]+sci[2]+max(soc[0], soc[1]));
	return(0);
}
