#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) (vec).begin(),(vec).end()
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n;
double val;
long long a,res;
int two,five;
map<pair<int,int>,int> cnt;
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>val;
		a=llround(val*1e9);
		two=five=0;
		while(a%2==0){
			two++;
			a/=2;
		}
		while(a%5==0){
			five++;
			a/=5;
		}
		cnt[make_pair(two,five)]++;
	}
	for(auto p1:cnt){
		for(auto p2:cnt){
			if((p1.first.first+p2.first.first)>=18&&(p1.first.second+p2.first.second)>=18){
				if(p1==p2) res+=(long long)(p1.second)*(long long)(p1.second-1);
				else res+=(long long)(p1.second)*(long long)(p2.second);
			}
		}
	}
	cout<<res/2LL<<endl;
	return 0;
}
