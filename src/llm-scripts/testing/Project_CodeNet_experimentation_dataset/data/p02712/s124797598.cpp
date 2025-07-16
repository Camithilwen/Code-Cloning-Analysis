#include <stdio.h>
int main() {
	int n;
	long long int val = 0;
	scanf("%d",&n);
	
	for (int i = 1 ; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			continue;
		}
		else if (i % 3 == 0)
		{
			continue;
		}
		else if (i % 5 == 0)
		{
			continue;
		}
		else
		{
			val += i;
		}
	}
	printf("%lld",val);
	return 0;
}