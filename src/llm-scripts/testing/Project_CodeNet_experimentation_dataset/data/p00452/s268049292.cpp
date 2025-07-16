#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

ll M,N,P[1001];

int main(){
	while(scanf("%lld%lld",&N,&M),N){
		for(int i=0;i<N;i++) scanf("%lld",&P[i]);
		vector<ll> d;
		for(int i=0;i<=N;i++) for(int j=0;j<=N;j++)
			d.push_back(P[i]+P[j]);
		sort(d.begin(),d.end());
		d.erase(unique(d.begin(),d.end()),d.end());
		vector<ll>::iterator it;
		ll res=0;
		for(int i=0;i<d.size();i++){
			it=upper_bound(d.begin(),d.end(),M-d[i]);
			if(it!=d.begin()){
				it--;
				res=max(res,*it+d[i]);
			}
		}
		printf("%lld\n",res);
	}
}