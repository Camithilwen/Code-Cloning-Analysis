//#pragma GCC optimize(3)
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define mxlen 1000+9
#define inf 1000009
#define INF (int)1e9
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;

char s1[inf],s2[inf];
int q[inf*2],head=inf,tail=inf-1;

int main(){
	int n;
	rd(n)
	scanf("%s%s",&s1,&s2);
	q[++tail]=n+1;
	int pos=n+1,cnt=0,ans=0;
	for (int i=n;i>=1;i--){
		int tmp=pos;
		while (pos>0 && (pos>i || s1[pos-1]!=s2[i-1])){
			pos--;
		}
		if (pos==0){
			puts("-1");
			return 0;
		}
		if (tmp==pos){
			while (head<=tail && q[tail]-cnt>=i){
				tail--;
			}
			q[++tail]=i+cnt;
		}
		else{
			cnt++;
			if (i!=pos){
				ans=max(ans,tail-head+1);
				q[--head]=pos+cnt;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}