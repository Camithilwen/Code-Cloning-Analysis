#include<stdio.h>
int num[4];
int main()
{
	int n,d1,d2;
	scanf("%d%d%d",&n,&d1,&d2);
	int num1=0,num2=0;
	while((d1&1)==0)
	{
		num1++;
		d1>>=1;
	}
	while((d2&1)==0)
	{
		num2++;
		d2>>=1;
	}
	for(int i=0;i<(n<<1);i++)
	{
		for(int j=0;j<(n<<1);j++)
		{
			int tp1,tp2;
			if(num1&1)
			{
				tp1=((i>>(num1>>1))&1);
			}
			else
			{
				tp1=(((i>>(num1>>1))+(j>>(num1>>1)))&1);
			}
			if(num2&1)
			{
				tp2=((i>>(num2>>1))&1);
			}
			else
			{
				tp2=(((i>>(num2>>1))+(j>>(num2>>1)))&1);
			}
			num[tp1+tp1+tp2]++;
		}
	}
	int wz;
	for(wz=0;wz<4;wz++)
	{
		if(num[wz]>=n*n)
		{
			break;
		}
	}
	int rm=n*n;
	for(int i=0;i<(n<<1);i++)
	{
		for(int j=0;j<(n<<1);j++)
		{
			int tp1,tp2;
			if(num1&1)
			{
				tp1=((i>>(num1>>1))&1);
			}
			else
			{
				tp1=(((i>>(num1>>1))+(j>>(num1>>1)))&1);
			}
			if(num2&1)
			{
				tp2=((i>>(num2>>1))&1);
			}
			else
			{
				tp2=(((i>>(num2>>1))+(j>>(num2>>1)))&1);
			}
			if(tp1+tp1+tp2==wz)
			{
				printf("%d %d\n",i,j);
				rm--;
				if(rm==0)
				{
					return 0;
				}
			}
		}
	}
	return 0;
}