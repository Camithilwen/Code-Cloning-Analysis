#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#define scanf_s scanf
#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pub push_back
using namespace std;
typedef long long int llint;
const llint one = 1;
const llint big = (one<<30);

bool solve(void){
	int N,Q,i,j,k,gen,a,ans=0,ansa;
	vector<int> date[50];
	scanf("%d %d",&N,&Q);
	if(N==0){return false;}
	ansa=Q-1;
	for(i=0;i<N;i++){
		scanf("%d",&j);
		for(;j>0;j--){
			scanf("%d",&a);
			date[i].pub(a);
		}
	}
	for(i=1;i<100;i++){
		gen=0;
		for(j=0;j<N;j++){
			for(k=0;k<date[j].size();k++){
				if(date[j][k]==i){ gen++; }
			}
		}
		if(ansa<gen){
			ansa=gen;ans=i;
		}
	}
	if(i==100){printf("%d\n",ans);}
	return true;
}
int main(void){while(solve()){}return 0;}