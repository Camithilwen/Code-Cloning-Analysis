#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int Max_N=1010;

int A[Max_N][Max_N];


int main(){
	int N;
	cin >> N;
	rep(i,N){
		rep(j,N-1){
			int a;
			cin >> a;
			a--;
			A[i][j]=a;
		}
	}
	vector<int> op(N);
	int ans=0, sum=N;
	queue<int> q1, q2;	
	rep(a,N){
		int n=A[a][0], m=op[n];
		if(n<a) continue;
		if(A[n][m]==a) q1.push(a);
	}
	while(sum){
		ans++;
		if(q1.empty()){
			cout << -1 << endl;
			return 0;
		}
		while(!q1.empty()){
			int a=q1.front(); q1.pop();
			int n=A[a][op[a]], m=op[n];
			q2.push(a), q2.push(n);
			op[a]++; op[n]++;
			if(op[a]==N-1) op[a]=-1, sum--;
			if(op[n]==N-1) op[n]=-1, sum--;
		}
		vector<bool> pushed(N);
		while(!q2.empty()){
			int a=q2.front(); q2.pop();
			if(op[a]==-1) continue;
			int n=A[a][op[a]], m=op[n];
			if(pushed[n]) continue;
			if(A[n][m]==a) q1.push(a), pushed[a]=true;
		}
	}
	cout << ans << endl;

	return 0;
}