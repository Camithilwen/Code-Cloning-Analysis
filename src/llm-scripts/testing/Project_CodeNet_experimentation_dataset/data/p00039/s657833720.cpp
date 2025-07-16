#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iostream>


using namespace std;


int main()
{
	char* ara = "IVXLCDM";
	int num[] = { 1, 5, 10, 50, 100, 500, 1000 };

	char buf[101];
	while (scanf("%s\n", buf) != EOF)
	{
		int len = strlen(buf);
		int n[100];
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (buf[i] == ara[j])
				{
					n[i] = num[j];
					break;
				}
			}
		}
		for (int i = 0; i < len-1; ++i)
			n[i] *= n[i] < n[i+1] ? -1 : 1;

		int res = 0;
		for (int i = 0; i < len; ++i)
			res += n[i];

		printf("%d\n", res);
	}

	return 0;
}