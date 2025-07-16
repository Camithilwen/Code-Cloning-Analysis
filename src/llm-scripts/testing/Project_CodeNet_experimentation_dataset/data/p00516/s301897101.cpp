#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main ()
{
	int M,N,mo[10000],sk[10000]={};
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
	{
		cin>>mo[i];
	}
	for(int i=0;i<M;i++)
	{
		int aa;
		cin>>aa;
		for(int q=0;q<N;q++)
		{
			if(mo[q]<=aa){sk[q]++;
			break;
			}
		}
	}
	int z=0,b=0;
	for(int i=0;i<N;i++)
	{
		if(sk[i]>b){
			b=sk[i];
			z=i;
		}
	}
	z++;
	cout<<z<<endl;
return 0;
}