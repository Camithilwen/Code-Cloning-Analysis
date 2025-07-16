#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<vi>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> in(n,0);
	vector<int> used(n,0);
	int d[101001]={};
	int ans=0;
	FOR(i,0,n){
		cin>>a[i];
		a[i]--;
		if(i==0){
			if(a[i]!=0){
				ans++;
				a[i]=0;
			}
			continue;
		}
		//g[i].PB(a[i]);
		in[a[i]]++;
	}
	queue<int> q;
	used[0]=1;
	FOR(i,1,n){
		if(in[i]==0)q.push(i);
	}
	while (q.size()) {
		int nw=q.front();
		q.pop();
		int nd=d[nw];
		//cerr<<nw<<" "<<nd<<endl;
		if(used[nw])continue;
		used[nw]=1;
		if(nd>=k-1&&a[nw]!=0){
			ans++;
		}else{
			if(a[nw]!=0)d[a[nw]]=max(d[a[nw]],nd+1);
		}
		in[a[nw]]--;
		if(in[a[nw]]==0)q.push(a[nw]);

	}

	cout<<ans<<endl;

	return 0;
}
