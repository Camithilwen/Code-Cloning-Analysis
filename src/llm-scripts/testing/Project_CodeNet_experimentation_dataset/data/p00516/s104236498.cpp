#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;i++)
#define FORVEC(i, v) for(int i = 0;i < v.size();i++)

#define INF 1000000000
#define pb(a) push_back(a)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int,int>
#define all(vec) (vec.begin()),(vec.end())
#define ll long long int;
#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x;
#define bit(n) (1<<(n))


template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
	int n,m,a[1000],b,p[1000]={};
	cin>>n>>m;
	REP(i,n){
		cin>>a[i];
	}
	REP(i,m){
		cin>>b;
		REP(j,n){
			if(a[j]<=b){
				p[j]++;
				break;
			}
		}
	}
	int mx=0,mxi;
	REP(i,n){
		//cout<<" "<<p[i]<<"\n";
		if(p[i]>mx){
			mx=p[i];
			mxi=i;
		}
	}
	cout<<mxi+1<<"\n";
	return 0;
}