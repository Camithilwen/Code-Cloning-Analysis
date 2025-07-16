#include<bits/stdc++.h>
using namespace std;
int n,offset,j,pre,ans;
string s,t;
deque<int> q;
int main()
{
	cin>>n>>s>>t;
	q.push_back(n);j=n-1;
	for (int i=n-1;i>=0;i--)
	{
		pre=j;
		while(j>=0 && (j>i || s[j]!=t[i])) j--;
		if (j<0) 
		{
			printf("-1\n");
			return 0;
		}
		if (pre==j)
		{
			while(!q.empty() && q.back()-offset>=i) q.pop_back();
			q.push_back(i+offset); 
 		}
 		else
 		{
 			offset++;
 			if (i!=j)
 			{
 				ans=max(ans,(int)q.size());
 				q.push_front(j+offset); 
			 }
		}
	} 
	cout<<ans<<endl;
	return 0;
}