#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 300005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,ans=300005,l[N],r[N];
char s[N];
int main() {
	cin>>n;
	rep1(i,1,n)cin>>s[i];
	rep1(i,2,n){
		l[i]=l[i-1]+(s[i-1]=='W');
	}
	ford(i,n-1,1){
		r[i]=r[i+1]+(s[i+1]=='E');
	}
	rep1(i,1,n){
		if(ans>l[i]+r[i]){
			ans=l[i]+r[i];
		} 
	}
	cout<<ans;
	return 0;
}
