#include<bits/stdc++.h>
#define no {puts("No");return 0;}
#define yes {puts("Yes");return 0;}
#define nc() getchar()
using namespace std;
const int N=300010;

/*inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}*/
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
 
int c[N],n;

void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=x&-x;
	}
}

int query(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}

int a[N],fu[N],s[N];
bool vis[N];

int main(){
	n=read();
	int s1=0,s2=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			int x;
			x=read();
			if(i==1){
				if(x%3==0){
					a[j]=x/3;
					
					fu[j]=1;
					if(j&1) s1++;
					
					else s2++;
				}else{
					if(x%3!=1) {no;}
					a[j]=x/3+1;
				}
				if(vis[a[j]]) {no;}
				if((j&1)^(a[j]&1)) {no;}
				vis[a[j]]=1;
			}
			else{
				if(fu[j]){
					if(x!=a[j]*3-i+1) {no;}
				}else{
			//		printf("a(%d)=%d\n",j,a[j]);
					if(x!=(a[j]-1)*3+i) {no;}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);cout<<endl;
	
	int i;
	
	if(n&1) i=n;else i=n-1;
	
	for(;i>0;i-=2){
		s2+=query(a[i]);
		add(a[i],1);
	}
	
	if(n&1) i=n-1;else i=n;
	
	memset(c,0,sizeof(c));
	
	for(;i>0;i-=2){
		s1+=query(a[i]);
		add(a[i],1);
	}
	
	
//	printf("%d %d\n",s1,s2);
	
	if(s1%2==0&&s2%2==0) {yes;}
	else {no;}
	
	return 1;
}
			
	