#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 100000000000000000LL
using namespace std;

int main()
{
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	vector<int> v[100000];
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int c=0;
	vector<int> conn[100000];
	int d[100000], e[100000]={};
	fill(d, d+n, -1);
	set<int> st;
	for(int i=0; i<n; i++){
		st.insert(i);
	}
	vector<int> w;
	while(!st.empty()){
		auto begin=st.begin();
		w.push_back(*begin);
		conn[c].push_back(*begin);
		d[*begin]=0;
        if(v[*begin].empty()) e[c]=2;
		st.erase(begin);
		while(!w.empty()){
			int x=w.back();
			w.pop_back();
			for(int i=0; i<v[x].size(); i++){
				if(d[v[x][i]]==-1){
					d[v[x][i]]=(d[x]+1)%2;
				}else if(d[v[x][i]]==d[x]){
					e[c]=1;
				}
				if(st.find(v[x][i])==st.end()) continue;
				w.push_back(v[x][i]);
				conn[c].push_back(v[x][i]);
				st.erase(v[x][i]);
			}
		}
		c++;
	}
	long long int cn2=0, cn0=0, cn1=0, ans=0;
	for(int i=0; i<c; i++){
		if(e[i]==2){
			cn2++;
		}else if(e[i]==1){
			cn1++;
		}else{
			cn0++;
		}
	}
	for(int i=0; i<c; i++){
		if(e[i]==2){
          ans=ans+n;
		}else if(e[i]==1){
		  ans=ans+cn2*conn[i].size()+cn0+cn1;
		}else{
          ans=ans+cn2*conn[i].size()+2*cn0+cn1;
		}
	}
	long long int N=(long long int)n;
	printf("%lld\n", ans);
	return 0;
}