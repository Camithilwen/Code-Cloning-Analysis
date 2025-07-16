//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-')
		jp = getchar();
	if (jp == '-')
		fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
char s[12];
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	if (n & 1)
		puts("No");
	else
	{
		for (int i = 0; i < n; i += 2)
			if (s[i] != 'h' || s[i + 1] != 'i')
			{
				puts("No");
				return 0;
			}
		puts("Yes");
	}
	return 0;
}
