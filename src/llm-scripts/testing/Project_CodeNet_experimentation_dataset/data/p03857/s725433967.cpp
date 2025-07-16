//hate penalty

#include <bits/stdc++.h>
using namespace std;

int dsu[200001], dsu2[200001];
map <pair<int, int> ,int> mp;

int find(int x){
	if (dsu[x]) return dsu[x]=find(dsu[x]);
	return x;
}

int find2(int x){
	if (dsu2[x]) return dsu2[x]=find2(dsu2[x]);
	return x;
}

int main(){
	int n, k, l;
	cin >> n >> k >> l;
	int x, y;
	for (int i=1; i<=k; i++){
		cin >> x >> y;
		if (find(x)!=find(y)){
			dsu[find(x)]=find(y);
		}
	}
	for (int i=1; i<=l; i++){
		cin >> x >> y;
		if (find2(x)!=find2(y)){
			dsu2[find2(x)]=find2(y);
		}
	}
	for (int i=1; i<=n; i++){
		mp[make_pair(find(i),find2(i))]++;
	}
	for (int i=1; i<n; i++){
		cout << mp[make_pair(find(i), find2(i))] << " ";
	}
	cout << mp[make_pair(find(n), find2(n))] << "\n";
}
