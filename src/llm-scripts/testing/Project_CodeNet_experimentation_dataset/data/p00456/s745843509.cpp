#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); i++)
#define SORT(c) sort((c).begin(),(c).end())
typedef vector<int> vi;
int main() {
	vi W(10),K(10);
	REP(i,10) scanf("%d",&W[i]);
	REP(i,10) scanf("%d",&K[i]);
	SORT(W); SORT(K);
	int w=0,k=0;
	REP(i,3) w+=W[9-i];
	REP(i,3) k+=K[9-i];
	printf("%d %d\n",w,k);
}