#include<cstdio>
#include<vector>

using namespace std;

int n,m;
vector<int> tomo[1001];
int ss[1001];


void saiki(int s,int dps){
		ss[s]=1;
	if(dps==2){
		return;
	}
	for(int i=0;i<tomo[s].size();i++){
		saiki(tomo[s][i],dps+1);
	}
}
	

int main(){
	while(1){
	scanf("%d%d",&n,&m);
	if(n==0&&m==0){
		break;
	}
	for(int i=0;i<1001;i++){
		ss[i]=0;		
		tomo[i].clear();
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		tomo[a].push_back(b);
		tomo[b].push_back(a);
	}
	
	saiki(1,0);
	
	int cont=0;
	for(int i=2;i<=n;i++){
		cont+=ss[i];
	}
	printf("%d\n",cont);
	}
}