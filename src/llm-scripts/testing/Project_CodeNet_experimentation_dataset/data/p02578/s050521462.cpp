#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int maximum;
	scanf("%d", &maximum);
	
	long long ans = 0;
	for(int i = 1; i < N; i++)
	{
		int person;
		scanf("%d", &person);
		
		if(person >= maximum)
			maximum = person;
			
		else
			ans += maximum - person;
	}
	
	printf("%lld", ans);
}
