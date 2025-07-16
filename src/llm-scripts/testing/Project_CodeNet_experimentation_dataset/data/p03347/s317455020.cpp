#include<iostream>
using namespace std;
long N,A[2<<17],ans;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	int i=0;
	while(i<N)
	{
		while(i+1<N&&A[i]+1==A[i+1])i++;
		if(A[i]>i||i+1<N&&A[i]+1<A[i+1])
		{
			cout<<-1<<endl;
			return 0;
		}
		ans+=A[i];
		i++;
	}
	cout<<ans<<endl;
}
