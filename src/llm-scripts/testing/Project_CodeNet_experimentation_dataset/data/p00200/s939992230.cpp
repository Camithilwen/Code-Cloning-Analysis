#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const double pi=acos(-1);
const double eps=1e-8;
const vi emp;

class Graph{
	private:
	int V;
	public:
	vvi Pro;
	Graph(int v){
		V=v;
		Pro=vvi(v,vi(v,inf));
		for(int i=0;i<v;i++) Pro[i][i]=0;
	}
	void add_edge(int x,int y,int c){
		Pro[x][y]=c;
		Pro[y][x]=c;
	}
	void Warshall(){
		for(int k=0;k<V;k++){
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					Pro[i][j]=min(Pro[i][j],Pro[i][k]+Pro[k][j]);
				}
			}
		}
	}
};

int V,E,N;

int main(){
	while(1){
		cin>>E>>V;
		if(!V&&!E) break;
		Graph cost(V),time(V);
		int s,t,c,l;
		for(int i=0;i<E;i++){
			cin>>s>>t>>c>>l;
			s--;
			t--;
			cost.add_edge(s,t,c);
			time.add_edge(s,t,l);
		}
		cost.Warshall();
		time.Warshall();
		cin>>N;
		bool r;
		for(int i=0;i<N;i++){
			cin>>s>>t>>r;
			s--;
			t--;
			if(r) cout<<time.Pro[s][t]<<endl;
			else cout<<cost.Pro[s][t]<<endl;
		}
	}
}