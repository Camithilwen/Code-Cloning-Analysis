#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;

	
int main()
{
	int h,w;cin>>h>>w;
	int a,b;cin>>a>>b;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if((j<a && i<b)||(j>=a && i>=b))cout<<0;
			else cout<<1;
		}
		cout<<"\n";
	}
	return 0;
}