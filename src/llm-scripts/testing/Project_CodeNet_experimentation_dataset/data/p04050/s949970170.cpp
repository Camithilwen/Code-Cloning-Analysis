#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,m;
int a[105];

int main()
{
	scanf("%d%d",&n,&m);
	int odd1 = 0,odd2 = 0;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&a[i]);
		if (a[i] & 1)
		{
			if (!odd1)
				odd1 = i;
			else if (!odd2)
				odd2 = i;
			else
			{
				puts("Impossible");
				return 0;
			}
		}
	}
	if (odd1)
		swap(a[odd1],a[1]);
	if (odd2)
		swap(a[odd2],a[m]);
	for (int i = 1;i <= m;i++)
		printf("%d ",a[i]);
	printf("\n");
	if (m == 1)
	{
		if (a[1] == 1)
		{
			puts("1");
			printf("1\n");
		}
		else
		{
			puts("2");
			printf("%d %d\n",a[1] - 1,1);
		}
		return 0;
	}
	printf("%d\n%d ",m - (a[m] == 1),a[1] + 1);
	for (int i = 2;i < m;i++)
		printf("%d ",a[i]);
	if (a[m] > 1)
		printf("%d",a[m] - 1);
	printf("\n");
	return 0;
}