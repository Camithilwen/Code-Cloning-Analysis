#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	int n;
	cin>>n;
	int A[n];
	int cnt = 0 ;
	for(int i=0 ; i<n ; i++)
		cin>>A[i];
	for(int i=0 ; i<n ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			for(int k=j+1 ; k<n ; k++)
			{
				if(A[i]+A[j]>A[k] && A[k]+A[j]>A[i] && A[i]+A[k]>A[j] && A[i]!=A[j] && A[j]!=A[k] && A[k]!=A[i])
					cnt++ ;
			}
		}
	}
	cout<<cnt;
}
