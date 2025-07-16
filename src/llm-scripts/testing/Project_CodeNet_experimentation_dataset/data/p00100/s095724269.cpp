#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main()
{
	
	int n;
	long long sn, x, y;
	vector<long long>p;
	map<long, long>m;
	while (1){
		m.clear();
		p.clear();
		cin >> n;

		if (n == 0)break;
		for (int i = 0; i < n; i++){
		cin >> sn >> x >> y;
			if (m.find(sn) == m.end()){
				p.push_back(sn);
			}
				m[sn] += x*y;
		}
		int flag = 0;
		for (int i = 0; i < p.size(); i++){
			if (m[p[i]] >= 1000000){
				cout << p[i] << endl;
				flag++;
			}
		}
		if (flag==0)cout << "NA" << endl;
	}
}