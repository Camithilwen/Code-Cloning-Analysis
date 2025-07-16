#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}
int n,a[200020];
map<int,int> cmp;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		cmp[a[i]]+=1;
	}
	sort(a,a+n);
	int ans  =0;
	for(int i=n-1;i>=0;i--){
		if(!cmp[a[i]])continue;
		cmp[a[i]]-=1;
		int b = a[i];
		b+=b&(-b);
		while(b!=(b&(-b)))b+=b&(-b);
		if(cmp[b-a[i]]){
			ans++;
			cmp[b-a[i]]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
