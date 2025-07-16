#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m&&n)
	{
		vector<int> a;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n%m;i++)
		{
			ans+=a[0];;
			a.erase(a.begin());
		}
		n-=n%m;
		for(int i=0;i<a.size();i++)ans+=a[i];
		for(int i=0;i<n/m;i++)
		{
			ans-=a[i*m];
		}
		cout<<ans<<endl;
	}
	
}