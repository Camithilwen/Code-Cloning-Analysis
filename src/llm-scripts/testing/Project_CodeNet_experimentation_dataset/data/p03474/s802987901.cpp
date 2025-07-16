#include <stdio.h>
#include <string.h>
int main ()
{
	int A, B;
	scanf ("%d %d", &A, &B);
	getchar ();
	char S[A+B+2] = {};
	scanf ("%s", &S);
	int len = strlen(S);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (48 <= S[i] && S[i] <= 57)
		{
			continue;
		}
		else if (48 > S[i] || S[i] > 57)
		{
			if ( i == A)
			{
				flag = 1;
				continue;
			}
			else if ( i != A)
			{
				flag = 0;
				break;
			}
		}
	}
	flag ? printf("Yes\n") : printf("No\n");
return 0;
}