#include <cstdio>
int a[100010],sum[2],n;
bool flag;
int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>1) sum[a[i]&1]++;
	}
	if (n==1)
	{
		if (a[1]&1) printf("Second\n");
		else printf("First\n");
		return 0;
	}
	flag=false;
	while (1)
	{
		if (!sum[0]&&!sum[1])
		{
			if (!flag) printf("Second\n");
			else printf("First\n");
			return 0;
		}
		if (sum[0]&1)
		{
			if (!flag) printf("First\n");
			else printf("Second\n");
			return 0;
		}
		if (sum[1]>1||!sum[1])
		{
			if (!flag) printf("Second\n");
			else printf("First\n");
			return 0;
		}
		int GCD=-1;
		for (int i=1;i<=n;i++)
			if (a[i]>1)
			{
				if (a[i]&1)
				{
					a[i]--;break;
				}
			}
		for (int i=1;i<=n;i++)	
			if (GCD==-1) GCD=a[i];
			else GCD=gcd(a[i],GCD);
		sum[0]=sum[1]=0;
		for (int i=1;i<=n;i++)
		{
			a[i]/=GCD;
			if (a[i]>1) sum[a[i]&1]++;
		}
		flag^=1;
	}
	return 0;
}
//all is 1: who faces even number of even number, lose./odd number of even number, win.