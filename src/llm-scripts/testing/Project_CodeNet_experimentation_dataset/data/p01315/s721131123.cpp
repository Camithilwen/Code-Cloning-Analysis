#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

class Plant{
public:
	string name;
	int d,m;
	bool operator<(const Plant plant)const{
		if(m*plant.d==plant.m*d){
			return name<plant.name;
		}else{
			return m*plant.d>plant.m*d;
		}
	}
};

vector<Plant> plants;

int main() {
	int n;
	while(n=in()){
		plants.clear();
		string l;
		int p,a,b,c,d,e,f,s,m;
		int i;
		for(i=0;i<n;i++){
			cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
			Plant plant;
			plant.name=l;
			plant.d=a+b+c+(d+e)*m;
			plant.m=f*s*m-p;
			plants.push_back(plant);
		}
		sort(plants.begin(),plants.end());
		for(i=0;i<n;i++){
			cout<<plants[i].name<<endl;
//cout<<plants[i].d<<" "<<plants[i].m<<endl;
		}
		cout<<"#\n";
	}
	return 0;
}