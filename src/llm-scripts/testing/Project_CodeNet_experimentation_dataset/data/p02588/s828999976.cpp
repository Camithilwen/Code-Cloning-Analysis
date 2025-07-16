#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
void read(int &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void read(ll &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void Min(int &x,int y){	
	if (x>y)x=y;
}
void Min(ll &x,ll y){	
	if (x>y)x=y;
}
void Max(int &x,int y){	
	if (x<y)x=y;
}
void Max(ll &x,ll y){	
	if (x<y)x=y;
}

#define bas 50
ll cnt[105][105];
char s[50];
int main(){
//	freopen("1.in","r",stdin);
	int n,i,j,k,l;
	ll x,res=0;
	
	read(n);
	/*
		cnt2[i]+cnt2[j]>=0
		cnt5[i]+cnt5[j]>=0	
	*/
	int m,ct2,ct5;
	for (i=1;i<=n;i++){
		scanf("%s",s);
		m=strlen(s);
		x=0; ct2=ct5=0;
		for (j=0;j<m;j++){
			if (s[j]!='.'){
				x=(x<<1)+(x<<3)+(s[j]^48);
			}
			else{
				ct2-=m-j-1;
				ct5-=m-j-1;
			}
		}
		for (;x&&x%2==0;)x/=2,ct2++;
		for (;x&&x%5==0;)x/=5,ct5++;
		cnt[bas+ct2][bas+ct5]++;
		if (ct2>=0&&ct5>=0)res--;
//		printf("%d %d\n",ct2,ct5);
	}
	for (i=-50;i<=50;i++){
		for (j=-50;j<=50;j++)if (cnt[i+bas][j+bas]){
			for (k=-i;k<=50;k++){
				for (l=-j;l<=50;l++){
					res+=cnt[i+bas][j+bas]*cnt[k+bas][l+bas];
				}
			}
		}
	}
	printf("%lld\n",res/2);
	return 0;
}