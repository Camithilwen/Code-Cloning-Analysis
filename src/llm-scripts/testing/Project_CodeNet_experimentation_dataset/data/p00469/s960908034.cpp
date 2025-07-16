#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,n) for(int i=1;i<=n;i++)

vector<int> card[10];
map<stack<int> ,int> check;
int visit[10];

stack<int> ub;
int cont;

void saiki(int dep,int k,int n){
	if(dep==k){
		if(check[ub]==0){
			check[ub]=1;
			cont++;
		}
		return;
	}
	
	rep(i,n){
		if(visit[i]==0){
			visit[i]=1;
			rep(j,card[i].size()){
				ub.push(card[i][j]);
			}
			
			saiki(dep+1,k,n);
			
			rep(j,card[i].size()){
				ub.pop();
			}
			visit[i]=0;
		}
	}
}

int main(){
	while(1){
		int n;
		int k;
		
		scanf("%d%d",&n,&k);
		if(n==0)break;
		
		rep(i,10){
			card[i].clear();
			visit[i]=0;
		}
		
		check.clear();
		cont=0;
		
		rep(i,n){
			int a;
			scanf("%d",&a);
			
			if(a<10){
				card[i].push_back(a);
			}else{
				card[i].push_back(a/10);
				card[i].push_back(a%10);
			}
		}
		
		saiki(0,k,n);
		
		printf("%d\n",cont);
	}
}