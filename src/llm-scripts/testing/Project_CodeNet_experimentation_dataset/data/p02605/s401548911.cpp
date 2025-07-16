#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
// please, read the question correctly (do you need set or multiset)???
const int N=200010; //check the limits, dummy
int x[N], y[N];
int n, m;
char s[N][11];
int main(){
	int t;
	// while(){
	scanf("%d",&n);
	vector<pair<int,int>>v1,v2, v3, v4, v5, v6;
	for(int i=0; i<n; ++i){
		scanf("%d%d%s",x+i, y+i, s[i]);
		if(s[i][0]=='U'){
			v1.push_back(mk(x[i], i));
			v5.push_back(mk(y[i], i));
		}
		else if(s[i][0]=='D'){
			v2.push_back(mk(x[i], i));
			v6.push_back(mk(y[i], i));
		}
		else if(s[i][0]=='R'){
			v3.push_back(mk(x[i], i));
		}
		else{
			v4.push_back(mk(x[i], i));
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	sort(v4.begin(), v4.end());

	sort(v5.begin(), v5.end());
	sort(v6.begin(), v6.end());

	int ans=1e9;
	int j=0, j1=0, j2=0;
	map<int, int> mp, mp1, mp2;
	for(int i=0; i<v4.size(); ++i){
		for(j;j<v1.size(); ++j){
			if(v1[j].fs>v4[i].fs)break;
			auto tmp=v1[j].sc;
			mp[x[tmp]-y[tmp]]=x[tmp];
		}
		auto tmp=v4[i].sc;
		if(mp.count(x[tmp]-y[tmp])){
			ans=min(ans, (x[tmp]-mp[x[tmp]-y[tmp]])*10);
		}

		for(j1;j1<v3.size(); ++j1){
			if(v3[j1].fs>v4[i].fs)break;
			auto tmp=v3[j1].sc;
			mp1[y[tmp]]=x[tmp];
		}
		 tmp=v4[i].sc;
		if(mp1.count(y[tmp])){
			ans=min(ans, (x[tmp]-mp1[y[tmp]])*5);
		}

		for(j2; j2<v2.size(); ++j2){
			if(v2[j2].fs>v4[i].fs)break;
			auto tmp=v2[j2].sc;
			mp2[x[tmp]+y[tmp]]=x[tmp];
		}
		 tmp=v4[i].sc;
		if(mp2.count(x[tmp]+y[tmp])){
			ans=min(ans, (x[tmp]-mp2[x[tmp]+y[tmp]])*10);
		}
	}
	mp.clear();
	mp1.clear();
	j=(int)v1.size()-1;
	j1=(int)v2.size()-1;
	for(int i=(int)(v3.size())-1; i>=0; --i){
		for(j; j>=0; --j){
			if(v1[j].fs<v3[i].fs)break;
			auto tmp=v1[j].sc;
			mp[x[tmp]+y[tmp]]=x[tmp];
		}
		auto tmp=v3[i].sc;
		if(mp.count(x[tmp]+y[tmp])){
			ans=min(ans, (mp[x[tmp]+y[tmp]]-x[tmp])*10);
		}

		for(j1; j1>=0; --j1){
			if(v2[j1].fs<v3[i].fs)break;
			auto tmp=v2[j1].sc;
			mp1[x[tmp]-y[tmp]]=x[tmp];
		}
		 tmp=v3[i].sc;
		if(mp1.count(x[tmp]-y[tmp])){
			ans=min(ans, (mp1[x[tmp]-y[tmp]]-x[tmp])*10);
		}
	}

	j=0;
	mp.clear();
	for(int i=0; i<v6.size(); ++i){
		for(j; j<v5.size(); ++j){
			if(v5[j].fs>v6[i].fs)break;
			auto tmp=v5[j].sc;
			mp[x[tmp]]=y[tmp];
		}
		auto tmp=v6[i].sc;
		if(mp.count(x[tmp])){
			ans=min(ans, (y[tmp]-mp[x[tmp]])*5);
		}
	}
	if(ans==1e9)
		printf("SAFE\n");
	else
		cout<<ans<<endl;
	// }
}