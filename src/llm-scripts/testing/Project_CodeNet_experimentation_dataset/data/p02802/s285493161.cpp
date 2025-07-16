#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int N,M;
	cin>>N>>M;
	int freq[N+1];
	memset(freq,0,sizeof(freq));
	int i,j,k;
	bool check[N+1];
	memset(check,false,sizeof(check));
	string s;
	for(i=1;i<=M;i++)
	{
		cin>>j>>s;
		if(s.compare("AC")==0)
		{
			check[j]=true;
		}
		else
		{
			if(check[j]==false)
			freq[j]++;
		}
	}
	j=0;
	k=0;
	for(i=1;i<=N;i++)
	{
		if(check[i])
		{
			j++;
			k=k+freq[i];
		}
	}
	cout<<j<<" "<<k;
	return 0;
}