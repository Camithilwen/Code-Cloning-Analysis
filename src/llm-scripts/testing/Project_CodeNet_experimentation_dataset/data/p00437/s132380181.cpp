#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct Info {
	int i,j,k;
	Info(int _i,int _j,int _k) {i=_i,j=_j,k=_k;}
};
vector<Info> info[2];
int result[300];
int main() {
	int a,b,c,N;
	while(scanf("%d %d %d",&a,&b,&c),a|b|c) {
		scanf("%d",&N);
		info[0].clear();
		info[1].clear();
		memset(result,0,sizeof(result));
		for(int i=0;i<N;i++) {
			int I,J,K,R;
			scanf("%d %d %d %d",&I,&J,&K,&R);
			info[R].push_back(Info(I-1,J-1,K-1));
		}
		for(int i=0;i<info[1].size();i++) {
			Info I=info[1][i];
			result[I.i]=result[I.j]=result[I.k]=1;
		}
		for(int i=0;i<info[0].size();i++) {
			Info I=info[0][i];
			if(result[I.i]==1&&result[I.j]==1) result[I.k]=2;
			if(result[I.i]==1&&result[I.k]==1) result[I.j]=2;
			if(result[I.j]==1&&result[I.k]==1) result[I.i]=2;
		}
		for(int i=0;i<(a+b+c);i++) {
			printf("%d\n",(result[i]==2)?0:(result[i]==0)?2:1);
		}
	}
}