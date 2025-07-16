#include <algorithm>
#include <cstdio>
const int N=2005;
int l[N][N],r[N][N];
bool a[N][N];
char s[N];
int main(){
	int h,w;
	scanf("%d%d\n",&h,&w);
	for (int i=0;i<h;i++){
		scanf("%s",s);
		for (int j=0;j<w;j++) a[i][j]=(s[j]=='#');
	}
	for (int i=h-1;i;i--){
		for (int j=0;j<w;j++) a[i][j]^=a[i-1][j];
		for (int j=w-1;j;j--) a[i][j]^=a[i][j-1];
		a[i][0]=a[i][w]=1;
		for (int j=0;j<w;j++)
			if (a[i][j]) l[i][j]=j;else l[i][j]=l[i][j-1];
		for (int j=w;j;j--)
			if (a[i][j]) r[i][j]=j;else r[i][j]=r[i][j+1];
	}
	int ans=std::max(h,w);
	for (int j=1;j<w;j++)
		for (int i=1,k=0,L=0,R=w;i<h;i++)
		if (a[i][j]) k=i,L=0,R=w;
		else{
			L=std::max(L,l[i][j]);
			R=std::min(R,r[i][j]);
			ans=std::max(ans,(R-L)*(i-k+1));
		}
	printf("%d\n",ans);
}