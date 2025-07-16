#include<cstdio>
#include<algorithm>

using namespace std;
int main(void)
{
	double a[10];
	double v[2];
	double ans;
	while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&v[0],&v[1]) != EOF)
	{
		double all = 0;
		double kari = 0;
		for(int i = 0;i < 10;i++) all += a[i];
		ans = (v[0] * all) / (v[0] + v[1]);
		if(ans == 0) printf("1\n");
		else
		{
			for(int i = 0;i < 10;i++)
			{
				kari += a[i];
				if(kari >= ans)
				{
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
	return 0;
}