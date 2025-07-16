//j
#include <stdio.h>

int main ()
{
	int step= 0;
	int a, b, c; 
	
	scanf ("%d %d %d", &a, &b, &c);
	
	if (a<b)
	{
	for (int i=1; i <= a; i++)
		{
			if (b*i >= c)
			{
			printf ("%d", i);
			return 0;
			}
		}
	}
	
	if (b<a)
	{
	for (int j=1; j <= b; j++)
		{
			if (a*j >= c)
			{
			printf ("%d", j);
			return 0;
			}
		}
	}
	
	if (b=a)
	{
	for (int k=1; k <= b; k++)
		{
			if (a*k >= c)
			{
			printf ("%d",k);
			return 0;
			}
		}
	}
	
	return 0;
}