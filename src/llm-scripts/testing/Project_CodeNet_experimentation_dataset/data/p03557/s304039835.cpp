#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
#define int long long int
#define mod 1000000007
int binary_search(int arr[],int start,int end,int val)
{
	if(start>end)
	     return -1;
	else
	{
		int mid=(start+end)/2;
		if(arr[mid]<=val)
		    return binary_search(arr,mid+1,end,val);
		else
		{
			int x=mid;
			int y=binary_search(arr,start,mid-1,val);
			if(y==-1)
			    return x;
			else
			    return y;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int j,arr1[n],arr2[n],arr3[n];
	for(j=0;j<n;j++)
	   cin>>arr1[j];
	for(j=0;j<n;j++)
	    cin>>arr2[j];
	for(j=0;j<n;j++)
	     cin>>arr3[j];
	sort(arr1,arr1+n);
	sort(arr2,arr2+n);
	sort(arr3,arr3+n);
	int value[n]={0};
	for(j=0;j<n;j++)
	{
		int index=binary_search(arr3,0,n-1,arr2[j]);
		if(index!=-1)
		{
			value[j]=(n-index);
		}
	}
	int suffix[n]={0};
	suffix[n-1]=value[n-1];
	for(j=n-2;j>=0;j--)
	{
		suffix[j]=value[j]+suffix[j+1];
	}
	int answer=0;
	for(j=0;j<n;j++)
	{
		int index=binary_search(arr2,0,n-1,arr1[j]);
		if(index!=-1)
		{
			answer+=suffix[index];
		}
	}
	cout<<answer<<endl;
}
