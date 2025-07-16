#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0) break;
		double m,e,j;
		rep(i,0,n){
			cin>>m>>e>>j;
			if(max(m,max(e,j))==100) o('A');
			else if(m+e>=180) o('A');
			else if(m+e+j>=240) o('A');
			else if(m+e+j>=210) o('B');
			else if(m+e+j>=150 && max(m,e)>=80) o('B');
			else o('C');
		}

	}
}