#include<bits/stdc++.h>

using namespace std;

const int MAXN=1000010;

int cnt=0,G[100];

void Insertion_Sort(int s,int t,int n,int* A)
{
	for(int i=s+t;i<n;i+=t)
	{
		int key=A[i],j=i-t;
		while(j>=0&&A[j]>key)
		{
			A[j+t]=A[j];
			j-=t;
			cnt++;
		}
		if(A[j+t]!=key)
		{
			A[j+t]=key;
			//cnt++;
		}
	}
}

int main()
{
	for(int i=0;(G[i]=G[i-1]*3+1)<=MAXN;i++);
	static int n,A[MAXN];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int t;
	for(t=0;G[t]<=n;t++);
	printf("%d\n",t);
	for(int i=t-1;i>=0;i--)
		printf("%d%c",G[i],i==0?'\n':' ');
	for(int i=t-1;i>=0;i--)
		for(int j=0;j<G[i];j++)
			Insertion_Sort(j,G[i],n,A); 
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
		printf("%d\n",A[i]);
	return 0;
}