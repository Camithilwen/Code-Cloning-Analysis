#include <iostream>
using namespace std;
int n;
int A[100000];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	int x=A[n-1];
	int j=A[0]<x?1:0;
	for(int i=1;i<n-1;i++)
	{
		if (A[i]<=x) 
		{
			int aj=A[j];
			A[j]=A[i];
			A[i]=aj;
			j++;
		}
	}
	A[n-1]=A[j];
	A[j]=x;
	for (int i=0;i<j;i++)
	{
		if (i) cout <<' ';
		cout<<A[i];
	}
	if(j)cout<<' ';
	cout<<'['<<A[j]<<']';
	for(int i=j+1;i<n;i++)//bug here i=j+1
	{
		cout <<' '<<A[i];
	}
	cout<<endl;//bug here
}