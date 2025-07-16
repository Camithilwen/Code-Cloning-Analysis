#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 20003

int n;
int a[N];
string S,X,Y;
map<pair<string,string>,LL>mp;
LL ans;

inline int read(){
	int X=0,w=0;
	char ch=0;
	while (ch<'0' || ch>'9')
	  w|=ch=='-',ch=getchar();
	while (ch>='0' && ch<='9')
	  X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w ? -X : X;
}

int main(){
	n=read();
	cin>>S;
	X=S.substr(0,n);
	Y=S.substr(n,n);
	reverse(Y.begin(),Y.end());
	for (int i=0;i<1<<n;i++){
		int res=i;
		string s1="",s2="";
		for (int j=0;j<n;j++){
			if (res%2==0) s1+=X[j];
			  else s2+=X[j];
			res/=2;
		}
		mp[make_pair(s1,s2)]++;
	}
	for (int i=0;i<1<<n;i++){
		int res=i;
		string s1="",s2="";
		for (int j=0;j<n;j++){
			if (res%2==0) s1+=Y[j];
			  else s2+=Y[j];
			res/=2;
		}
		ans+=mp[make_pair(s1,s2)];
	}
	printf("%lld\n",ans);
    return 0;
}