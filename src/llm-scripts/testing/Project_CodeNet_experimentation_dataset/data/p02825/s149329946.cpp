#include<cstdio>
#define For(i,A,B) for(i=A;i<=(B);++i)
char a[1005][1005];
void work(int x,int k){
	if(k==4){
		a[x][x]=a[x][x+1]=a[x][x+3]=a[x+1][x+3]=a[x+2][x]=a[x+3][x]=a[x+3][x+2]=a[x+3][x+3]='a';
		a[x+1][x]=a[x+1][x+1]=a[x+2][x+2]=a[x+2][x+3]='b';
		a[x][x+2]=a[x+1][x+2]=a[x+2][x+1]=a[x+3][x+1]='c';
	}else if(k==5){
		a[x][x]=a[x][x+1]=a[x][x+4]=a[x+1][x+4]=a[x+3][x]=a[x+4][x]=a[x+4][x+3]=a[x+4][x+4]='a';
		a[x][x+2]=a[x][x+3]=a[x+1][x]=a[x+2][x]=a[x+2][x+4]=a[x+3][x+4]=a[x+4][x+1]=a[x+4][x+2]='b';
		a[x+1][x+1]=a[x+1][x+2]=a[x+2][x+3]=a[x+3][x+3]='c';
	}else if(k==6){
		a[x][x]=a[x][x+1]=a[x][x+3]=a[x+1][x+3]=a[x+2][x+5]=a[x+3][x+2]=a[x+3][x+3]=a[x+3][x+5]=a[x+4][x]=a[x+5][x]=a[x+5][x+4]=a[x+5][x+5]='a';
		a[x+1][x]=a[x+1][x+1]=a[x+2][x+2]=a[x+2][x+3]=a[x+4][x+1]=a[x+4][x+4]=a[x+4][x+5]=a[x+5][x+1]='b';
		a[x][x+2]=a[x+1][x+2]=a[x+2][x+4]=a[x+3][x+4]='c';
	}else{
		a[x][x]=a[x][x+1]=a[x][x+6]=a[x+1][x+6]=a[x+2][x+2]=a[x+2][x+3]=a[x+3][x+4]=a[x+4][x+4]=a[x+5][x]=a[x+6][x]=a[x+6][x+5]=a[x+6][x+6]='a';
		a[x][x+2]=a[x][x+3]=a[x+2][x+6]=a[x+3][x]=a[x+3][x+6]=a[x+4][x]=a[x+6][x+3]=a[x+6][x+4]='b';
		a[x+1][x+1]=a[x+1][x+2]=a[x+1][x+5]=a[x+2][x+5]=a[x+4][x+1]=a[x+5][x+1]=a[x+5][x+4]=a[x+5][x+5]='c';
	}
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n==2)puts("-1");
	else if(n==3)puts("aa.\n..a\n..a");
	else{
		For(i,1,n)
			For(j,1,n)a[i][j]='.';
		For(i,0,(n>>2)-2)work((i<<2)+1,4);
		i=(n&3)+4;
		work(n-i+1,i);
		For(i,1,n)puts(a[i]+1);
	}
	return 0;
}