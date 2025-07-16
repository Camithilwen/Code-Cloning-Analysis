#include <stdio.h>
#include <string.h>
int main() {
	int a, b;
	scanf("%d %d",&a,&b);
	char str[a+b+1];
	scanf("%s",&str);
	int len = strlen(str);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (48 <= str[i] && str[i] <= 57)
		{
			continue;
		}
		else 
		{
			if (i == a)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	flag ? printf("Yes\n") : printf("No\n");
	return 0;
}