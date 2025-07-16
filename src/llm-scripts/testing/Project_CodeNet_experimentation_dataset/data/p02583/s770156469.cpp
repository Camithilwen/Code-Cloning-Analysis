#include <bits/stdc++.h>
using namespace std;

int lengths[105];
bool allDifferent(int len1, int len2, int len3)
{
	return (len1 != len2) && (len2 != len3) && (len3 != len1);
}

bool canFormTriangle(int len1, int len2, int len3)
{
	int maxLen = max(max(len1, len2), len3);
	return len1 + len2 + len3 - maxLen > maxLen;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
		scanf("%d", &lengths[i]);
	
	int ans = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = i + 1; j <= N; j++)
		{
			for(int k = j + 1; k <= N; k++)
			{
				if(allDifferent(lengths[i], lengths[j], lengths[k]) && canFormTriangle(lengths[i], lengths[j], lengths[k]))
					ans++;
			}
		}
	}
	
	printf("%d", ans);
}