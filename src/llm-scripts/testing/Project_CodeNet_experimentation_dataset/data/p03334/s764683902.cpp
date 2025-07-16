#include<bits/stdc++.h>
#define mo 1000000007
#define ny 499122177
#define maxn 1000000000000000000LL
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1; 
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
int n,m,d1,d2,i,j,flag,cnt,book[605][605];
void ss(int x){
	flag=0;
	while((x&3)==0){
		x>>=2;
		flag++;
	}
	if(x&1){
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if(((i>>flag)+(j>>flag))&1)
					book[i][j]=1;
	}
	else{
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if((i>>flag)&1)
					book[i][j]=1;
	}
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	n=read();d1=read();d2=read();
	m=n*2;
	ss(d1);
	ss(d2);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++){
			if(book[i][j]==0){
				pus(i,1);
				pus(j,2);
				cnt++;
			}
			if(cnt==n*n)
				return 0;
		}
  	return 0;
}