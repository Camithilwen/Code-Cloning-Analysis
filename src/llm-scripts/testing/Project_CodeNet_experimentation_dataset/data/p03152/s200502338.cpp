#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	ll n,m;
	cin>>n>>m;
	ll ans=1;
	vector<int> a(n),b(m),flag(n*m,0);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		a[i]--;
		if(flag[a[i]]>0){
			ans=0;
		}
		flag[a[i]]=1;
	}
	for(int i = 0; i < m; i++){
		cin>>b[i];
		b[i]--;
		if(flag[b[i]]>=2){
			ans=0;
		}
		if(flag[b[i]]>0) flag[b[i]]=3;
		else{
			flag[b[i]]=2;
		}
	}

	int j=-1,k=-1;
	for(int i = n*m-1; i >= 0 ; i--){
		if(flag[i]==3){
			j++;
			k++;
		}else if(flag[i]==2){
			ans*=j+1;
			ans%=mod;
			k++;
		}else if(flag[i]==1){
			ans*=k+1;
			ans%=mod;
			j++;
		}else{
			ans*=((j+1)*(k+1)-(n*m-(i+1)));
			ans%=mod;
		}
	}

	cout<<ans<<endl;

	return 0;
}