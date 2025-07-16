#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi frist
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int a[N],c[N],n,K;

int main(){
	read(n),read(K);
	rep(i,1,n){
		read(a[i]);
	}
	rep(k,1,K){
		memset(c,0,sizeof c);
		rep(i,1,n){
			int l=max(1,i-a[i]);
			int r=min(n,i+a[i]);
			c[l]++,c[r+1]--;
		}
		int flag=0;
		rep(i,1,n){
			c[i]+=c[i-1];
			a[i]=c[i];
			if(a[i]<n){
				flag=1;
			}
		}
		if(!flag){
			break;
		}
	}
	rep(i,1,n){
		printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
