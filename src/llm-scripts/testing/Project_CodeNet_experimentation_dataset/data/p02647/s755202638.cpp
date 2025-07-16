#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define ld long double
const int MxN = 200001 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)

/* VARIABLES */
int n , k ; 
VI a(MxN) ; 

/* END OF VARIABLES */



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	cin >> n >> k ; 
	FOR(i,0,n)
		cin >> a[i] ; 
	if(k>=3*log2((ld)n))
	{
		FOR(i,0,n)
			cout<<n<<' ';
		return 0;
	}
	FOR(i,0,k) {
		VI tmp(n+1) ; 
		FOR(j,0,n) {
			int l = max(0,j-a[j])  ; 
			int r = min(n-1,j+a[j]) ; 
			tmp[l]++;
			if(r+1 < n) 
				tmp[r+1]--;
		}
		FOR(j,1,n) {
			tmp[j] += tmp[j-1] ; 
		}
		FOR(j,0,n){
			a[j] = tmp[j] ; 
		}
	}
	
	FOR(i,0,n) 
	cout << a[i] << " " ;
	
	return 0 ; 
}

