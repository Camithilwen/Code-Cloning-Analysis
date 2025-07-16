#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n],b[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[n-i-1];
	}
	
	int val=-1;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i])
		{
			val=a[i];
			break;
		}
	}
	
	if(val==-1)
	{
		cout<<"Yes"<<endl;
		
		for(int i=0;i<n;i++)
		{
			cout<<b[i]<<' ';
		}
		cout<<endl;
	}
	else
	{
		vector<int> t_change,available;
		
		for(int i=0;i<n;i++)
		{
			if(a[i]!=val && b[i]!=val)
			{
				available.push_back(i);
			}
			if(a[i]==val && b[i]==val)
			{
				t_change.push_back(i);
			}
		}
		
		if(t_change.size()>available.size())
		{
			cout<<"No"<<endl;
		}
		else
		{
			
			for(auto i:t_change)
			{
				int ind=*(available.end()-1);
				
				swap(b[i],b[ind]);
				available.pop_back();
			}
			
			cout<<"Yes"<<endl;
		
			for(int i=0;i<n;i++)
			{
				cout<<b[i]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}