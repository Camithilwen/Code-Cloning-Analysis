#include <stdio.h>
char zf1[1000010],zf2[1000010];
struct SZt
{
	int l,r,h;
	SZt(){}
	SZt(int L,int R,int H)
	{
		l=L;
		r=R;
		h=H;
	}
};
SZt dl[1000010];
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("game.out","w",stdout);
	int n,jg=0,he=0,ta=0,py=0;
	scanf("%d%s%s",&n,zf1,zf2);
	bool bt=false;
	for(int i=0;i<n;i++)
	{
		if(zf1[i]!=zf2[i])
		{
			bt=true;
			break;
		}
	}
	if(!bt)
	{
		printf("0\n");
		return 0;
	}
	for(int i=n-1;i>=0;i--)
	{
		while(he<ta&&dl[he].l-py>i)
			he+=1;
		if(he<ta)
		{
			if(dl[he].h+py+1>jg)
				jg=dl[he].h+py+1;
			if(i>0&&zf2[i]==zf2[i-1])
				continue;
			py+=1;
			dl[he].r=i-1+py;
			int la=dl[ta-1].l-py;
			while(la>=0&&zf1[la]!=zf2[i])
				la-=1;
			if(la==-1)
			{
				printf("-1");
				return 0;
			}
			dl[ta]=SZt(la+py,dl[ta-1].r-1,1-py);
			ta+=1;
		}
		else
		{
			py=0;
			if(jg<1)jg=1;
			if(i>0&&zf2[i]==zf2[i-1])
				continue;
			int la=i;
			while(la>=0&&zf1[la]!=zf2[i])
				la-=1;
			if(la==i)continue;
			if(la==-1)
			{
				printf("-1");
				return 0;
			}
			dl[ta++]=SZt(la,i-1,1);
		}
	}
	printf("%d",jg);
	return 0;
}