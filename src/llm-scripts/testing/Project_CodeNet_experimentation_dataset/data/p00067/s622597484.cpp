#include<stdio.h>
char table[12][13];
void del(int i,int j){
	table[i][j]='0';
	if(i>0&&table[i-1][j]=='1')del(i-1,j);
	if(j>0&&table[i][j-1]=='1')del(i,j-1);
	if(i<11&&table[i+1][j]=='1')del(i+1,j);
	if(j<11&&table[i][j+1]=='1')del(i,j+1);
	return ;
}
int main(){
	while(~scanf("%s",table[0])){
		for(int i=1;i<12;i++)scanf("%s",table[i]);
		int ret=0;
		for(int i=0;i<12;i++)
			for(int j=0;j<12;j++)
				if(table[i][j]=='1'){
					ret++;
					del(i,j);
				}
		printf("%d\n",ret);
	}
}