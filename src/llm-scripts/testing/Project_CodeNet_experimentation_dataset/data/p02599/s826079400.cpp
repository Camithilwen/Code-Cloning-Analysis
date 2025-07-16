#include <bits/stdc++.h>
using namespace std;
int p[1000005];
 
int getSum(int* BIT,int idx){
	int sum=0;
	while(idx>0){
		sum+=BIT[idx];
		idx-=(idx&-idx);
	}
	return sum;
}
 
void update(int* BIT,int N,int idx,int val){
	while(idx<=N){
		BIT[idx]+=val;
		idx+=(idx&-idx);
	}
	return;
}
 
int main() {
	memset(p,0,sizeof(p));
	
	int N,i;
	scanf("%d",&N);
	int Q;
	scanf("%d",&Q);

	int A[N+1];
	for(i=1;i<=N;i++)
	scanf("%d",&A[i]);
	
	int *BIT=new int[N+1];
	for(i=0;i<=N;i++)
	BIT[i]=0;
	
	
	vector<pair<int,pair<int,int> > > queries(Q);
	for(i=0;i<Q;i++){
		scanf("%d %d",&queries[i].second.first,&queries[i].first);
		queries[i].second.second=i;
	}
	vector<int> ans(Q,0);
	sort(queries.begin(),queries.end());
	int j=0;
	for(i=1;i<=N;i++){
		if(p[A[i]]>0)
		update(BIT,N,p[A[i]],-1);
		p[A[i]]=i;
		update(BIT,N,i,1);
		while(j<Q&&queries[j].first==i){
			ans[queries[j].second.second]=getSum(BIT,i)-getSum(BIT,queries[j].second.first-1);
			++j;
		}
		if(j==Q)
		break;
	}
	
	for(int i=0;i<Q;i++)
	printf("%d\n",ans[i]);
	// your code goes here
	return 0;
} 
