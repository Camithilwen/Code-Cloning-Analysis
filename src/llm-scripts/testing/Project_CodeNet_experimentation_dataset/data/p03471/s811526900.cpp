#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n,y;
int main()
{
	cin >> n >> y;
	int ok=0;
	if(y%1000)
	{
		cout << -1 << ' ' << -1 << ' ' << -1;
		return 0;
	}
	else y/=1000;
	for(int i=0; !ok&&i<=y/10; i++)
		for(int j=0; j<=y/5; j++)
			if((y-i*10-j*5)>=0 && (y-i*10-j*5)+i+j == n)
			{
				cout << i << ' ' << j << ' ' << (y-i*10-j*5);
				ok=1;
				break;
			}
	if(!ok) cout << -1 << ' ' << -1 << ' ' << -1;
	return 0;
}
