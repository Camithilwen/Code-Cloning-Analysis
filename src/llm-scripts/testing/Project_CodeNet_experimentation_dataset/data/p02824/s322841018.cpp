#include<iostream>
#include<algorithm>
using namespace std;
int N;
long M,V,P;
long A[1<<17];
long po[1<<17];
main()
{
	cin>>N>>M>>V>>P;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int Li=-1,Ri=N-1;
	long okv=A[N-P];
	while(Ri>=0&&A[Ri]>=okv)Ri--;
	Ri++;
	while(Ri-Li>1)
	{
		int Mi=(Li+Ri)/2;
		long dist=A[Mi]+M;
		long ret=M*(V-1);
		int okid=Mi;
		for(int i=0;i<N;i++)
		{
			if(i==Mi)po[i]=-1;
			else
			{
				if(A[i]<=dist)
				{
					po[i]=min(dist-A[i],M);
					okid=i;
				}
				else po[i]=0;
				ret-=po[i];
			}
		}
		if(N-okid-1>=P)
		{
			Li=Mi;
			continue;
		}
		if(ret<=0)
		{
			Ri=Mi;
			continue;
		}
		int id=N-1;
		for(int i=0;i<P-1;i++)
		{
			if(id==Mi)id--;
			if(id<0)break;
			ret-=M-po[id];
			id--;
		}
		if(ret<=0)
		{
			Ri=Mi;
		}
		else Li=Mi;
	}
	cout<<N-Ri<<endl;
}
