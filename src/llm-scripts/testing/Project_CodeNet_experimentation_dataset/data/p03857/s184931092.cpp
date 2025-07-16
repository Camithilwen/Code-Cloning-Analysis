#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int x,y,z,n,m,road[200005],rail[200005],connect[200005];
pair<pair<int,int>,int> total[200005];

int root (int ind) {
	if (road[ind] == ind) return ind; else 
	return road[ind] = root(road[ind]);
}

void onion(int l, int r) {
	if (root(l) != root(r)) road[root(l)] = root(r);
}

int root2(int ind) {
	if (rail[ind] == ind) return ind; else 
	return rail[ind] = root2(rail[ind]);
}

void onion2(int l, int r) {
	if (root2(l) != root2(r)) rail[root2(l)] = root2(r);
}

int main() {
	cin >> x >> y >> z;
	for (int i = 0; i <= x; i++) {
		rail[i] = i;
		road[i] = i;
	}
	for (int i = 0; i < y; i++) {
		cin >> n >> m;
		onion(n,m);
	}
	for (int i = 0; i < z; i++) {
		cin >> n >> m;
		onion2(n,m);
	}
	for (int i = 1; i <= x; i++) {
		total[i] = make_pair(make_pair(root(i),root2(i)),i);
	}
	sort(total+1,total+1+x);
	total[x+1].f.f = total[x+1].f.s = -31415;
	stack<int> st; while (!st.empty()) st.pop();
	int a1 = 0,a2 = 0,b1 = 0,b2 = 0;
	for (int i = 1; i <= x+1; i++) {
		a1 = total[i].f.f, a2 = total[i].f.s;
		if (!(st.empty() || (a1 == b1 && a2 == b2))) {
			int tmp = st.size();
			while (!st.empty()) {
				connect[st.top()] += tmp-1;
				st.pop(); 
			}
		} 
		b1 = a1, b2 = a2;
		st.push(total[i].second);
	}
	for (int i = 1; i <= x; i++) {
		cout << connect[i]+1 << " ";
	}
}