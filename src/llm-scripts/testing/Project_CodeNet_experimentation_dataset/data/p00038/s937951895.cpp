#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[6] = {};
	while(scanf("%d",&a[0])!=EOF){
		for(int i=1;i<5;i++)scanf(",%d", &a[i]);
			int cnt=0,flag=true,card[13]={},max = 4;
		sort(a,a+5);
		for (int i=0;i<4;i++)for(int j=i+1;j<5;j++)
			if (a[i]==a[j])cnt++;
		int i=0;
		if(a[i]==1&&a[i+1]==10){
			i=1;
			max=5;
			a[5]=14;
		}
		for(;i<max;i++)if(a[i]+1!=a[i+1])flag=0;
if (cnt == 6)printf("four card\n");
else if (cnt == 4)printf("full house\n");
else if (flag)printf("straight\n");
else if (cnt == 3)printf("three card\n");
else if (cnt == 2)printf("two pair\n");
else if (cnt == 1)printf("one pair\n");
else printf("null\n");
}
}