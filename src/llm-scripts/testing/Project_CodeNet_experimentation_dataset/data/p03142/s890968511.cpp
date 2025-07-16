#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll N,M;
	cin >> N >> M;
	vector<ll> A(N+M-1),B(N+M-1),G[N],in_cnt(N,0);
	vector<bool> is_root(N,true);

	for(int i=0;i<N+M-1;i++){
		cin >> A[i] >> B[i];
		A[i]--,B[i]--;
		G[A[i]].push_back(B[i]);
		is_root[B[i]] = false;
		in_cnt[B[i]]++;
	}

	int root;
	for(int i=0;i<N-1;i++){
		if(is_root[i]) root = i;
	}

	vector<ll> pa(N,-1);
	queue<ll> q;
	q.push(root);

	while(q.size()){
		ll from = q.front();
		q.pop();
		for(auto to:G[from]){
			pa[to] = from;
			in_cnt[to]--;
			if(in_cnt[to] == 0){
				q.push(to);
			}
		}
	}

	pa[root] = -1;
	for(auto x:pa){
		cout << x+1 << "\n";
	}

}
