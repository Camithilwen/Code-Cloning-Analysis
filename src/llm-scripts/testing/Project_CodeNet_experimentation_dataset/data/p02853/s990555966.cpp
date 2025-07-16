#include <bits/stdc++.h>

using namespace std;

int main()
{
	int arr[4]={0,300000,200000,100000};
	int x,y;
	cin >> x >> y;
	int ans=0;
	if(x<=3) ans+=arr[x];
	if(y<=3) ans+=arr[y];
	if(x==1&&y==1) ans+=400000;
	cout << ans << endl;
}