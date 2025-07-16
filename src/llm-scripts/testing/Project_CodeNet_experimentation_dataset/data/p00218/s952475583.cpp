#include <stdio.h>
int main(){
	int i,n,pm,pj,pe;
	double avg,emav;
	char type;
	scanf("%d",&n);
	while(n!=0){
		for(i=0;i<n;i++){
			scanf("%d%d%d",&pm,&pe,&pj);
			avg = (pm+pe+pj) / 3.0;
			emav = (pm+pe) / 2.0;
			if(pm==100.0||pe==100.0||pj==100.0||emav>=90.0||avg>=80.0) type = 'A';
			else if(avg>=70.0) type = 'B';
			else if(avg>=50.0&&(pe>=80.0||pm>=80.0)) type = 'B';
			else type = 'C';
			printf("%c\n",type);
		}
		scanf("%d",&n);
	}
	return 0;
}