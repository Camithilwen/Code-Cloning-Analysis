#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define endl '\n'
using ll=long long;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=510000;
const int mod=1e9+7;
const ll oo=1e18+5;



int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int n;
	cin>>n;
	if(n<3) return cout<<-1,0;
	if(n==3){
		cout<<"aa.\n..a\n..a"<<endl;
		return 0;
	}
	vector<string> matrixx[8];
	// 4
	matrixx[4].push_back("aabc");
	matrixx[4].push_back("ddbc");
	matrixx[4].push_back("bcaa");
	matrixx[4].push_back("bcdd");
	// 5
	matrixx[5].push_back("aabba");
	matrixx[5].push_back("bcc.a");
	matrixx[5].push_back("b..cb ");
	matrixx[5].push_back("a..cb");
	matrixx[5].push_back("abbaa");
	// 6
	matrixx[6].push_back("aabc..");
	matrixx[6].push_back("ddbc..");
	matrixx[6].push_back("..aabc");
	matrixx[6].push_back("..ddbc");
	matrixx[6].push_back("bc..aa");
	matrixx[6].push_back("bc..dd");
	//7
	matrixx[7].push_back("aabbcc.");
	matrixx[7].push_back("dd.dd.a");
	matrixx[7].push_back("..d..da");
	matrixx[7].push_back("..d..db");
	matrixx[7].push_back("dd.dd.b");
	matrixx[7].push_back("..d..dc");
	matrixx[7].push_back("..d..dc");
	
	int rem=n%4;
	int k=n/4;
	if(rem) --k;
	int times=-1;
	//~ int loopp=0;
	for(int i=0;i<k*4;++i)
	{
		if(i%4==0) ++times;
		for(int j=0;j<times*4;++j) cout<<".";
		cout<<matrixx[4][i%4];
		for(int j=times*4+4;j<n;++j) cout<<".";
		cout<<endl;
	}
	++times;
	if(rem){
		for(int i=0;i<4+rem;++i){
			for(int j=0;j<times*4;++j) cout<<".";
			cout<<matrixx[rem+4][i%(rem+4)];
			cout<<endl;
		}
	}
	return 0;
}
