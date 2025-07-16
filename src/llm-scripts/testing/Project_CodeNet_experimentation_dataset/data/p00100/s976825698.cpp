#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long long> pil;

bool cmp(pil lhs, pil rhs)
{
	return (lhs.first < rhs.first);
}

int main()
{
	int n;
	while (cin >> n, n){
	
	vector<pil> p(n);
	
	int cnt = 0;
	for (int i = 0; i < n; i++){
			int a, b, c;
			bool f = true;
			cin >> a >> b >> c;
			for (int j = 0; j <= cnt; j++){
				if (p[j].first == a){
					p[j].second += b * c;
					f = false;
				}
			}
			if (f){
				p[cnt].first += a;
				p[cnt].second += b * c;
				cnt++;
			}
		}
		bool fl = true;
		for (int i = 0; i < cnt; i++){
			if (1000000 <= p[i].second){
				cout << p[i].first << endl;
				fl = false;
			}
		}
		if (fl){
			cout << "NA" << endl;
		}
	}
	return (0);
}