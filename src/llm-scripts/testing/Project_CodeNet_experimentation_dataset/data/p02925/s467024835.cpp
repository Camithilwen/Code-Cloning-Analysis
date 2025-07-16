#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;
int main() {
    int n;
    cin >> n;
	vector<queue<int>> q(n+1);
	for (int i=0;i<n; i++){
		for (int j=0;j<n-1;j++){
			int x;
			cin>>x;
			q[i].push(x-1);
		}
		q[i].push(n);
	}
	q[n].push(n);
	int ans=0;
	int cnt=n*(n-1);
	int f=1;
	vector<int>update;
	for (int i=0;i<n;i++){
		update.push_back(i);
	}
	while (cnt > 0){
		ans++;
		vector<int>update2;	
		for (int i : update){
			if (q[q[i].front()].front()==i && q[i].front()>i){
				update2.push_back(i);
				update2.push_back(q[i].front());
			}
		}
		for (int i:update2){
			q[i].pop();
			cnt--;
		}
		if (update2.empty()){
			f=0;
			break;
		}
	}
	if(f==0) cout<<-1<<endl;
	else cout<<ans<<endl;
}

