#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

struct cost{
	string name;
	double eff;
	
	bool operator<(const cost& a) const{
		if(eff != a.eff) return eff > a.eff;
		if(name != a.name) return name < a.name;
	}
};
	
int main(){
	double p, a, b, c, d, e, f, s, m;
	int n, i, j;
	string l;
	cost ls[51];
	while(1){
		cin >> n;
		if(!n) break;
		for(i=0;i<n;i++){
			cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			ls[i].name = l;
			ls[i].eff = (s*f*m-p)/(a+b+c+(d+e)*m);
		}
		sort(&ls[0], &ls[n]);
		for(i=0;i<n;i++){
			cout << ls[i].name << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}