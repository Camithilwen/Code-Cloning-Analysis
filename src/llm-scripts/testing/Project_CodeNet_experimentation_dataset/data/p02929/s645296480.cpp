#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
const int mod=1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int n,m;
char s[maxn<<1];

inline int read(){
    int x=0,f=1; char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int main(){
	n=read(); scanf("%s",s+1);
	int cnt=0; int res=1;
	for (int i=1;i<=(n<<1);i++){
		if (s[i]=='B'){if (cnt&1) res=1ll*res*cnt%mod,--cnt; else ++cnt;}
		else if (s[i]=='W'){if (cnt&1) ++cnt; else res=1ll*res*cnt%mod,--cnt;}
		if (cnt<0){puts("0"); return 0;}
	}
	if (cnt){puts("0"); return 0;}
	for (int i=1;i<=n;i++) res=1ll*res*i%mod;
	printf("%d\n",res);
    return 0;
}
