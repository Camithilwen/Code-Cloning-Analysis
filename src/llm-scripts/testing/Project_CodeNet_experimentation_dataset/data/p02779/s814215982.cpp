#include <iostream>
//#include<stack>
#include<set>
#include<bits/stdc++.h>
using namespace std;
//int f[10005];
//int chazhao(int x)
//{
//	if(x==f[x])
//	return x;
//	else
//	return f[x]=chazhao(f[x]);
//}

int main()
{
	set<int >ss;
	int n,x;
	cin>>n>>x;
	ss.insert(x);
	for(int i=1;i<n;i++)
	{
		cin>>x;
	  if(ss.count(x)==0)
	  ss.insert(x);
	  else
	  continue;
	}
   int k=ss.size();
   if(k==n)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
 return 0;
}