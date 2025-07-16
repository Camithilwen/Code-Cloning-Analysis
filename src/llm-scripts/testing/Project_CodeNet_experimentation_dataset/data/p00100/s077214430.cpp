#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	int ans[4000];
	
	for(;;)
	{
		cin >> n;
		if(n==0)
			break;
		int i,j;
		for(i=0,j=0;i<n;i++)
		{
			int num[4000];
			int flag=1;
			double a[4000],b[4000];
			double ans_max[4000];
			
			cin >> num[i] >> a[i] >> b[i] ;
			ans_max[i]=a[i]/10000.0*b[i];
			for(int l=i-1;l>=0;l--)
			{
				if(num[l]==num[i])
				{
//					cout << "in" << endl;
					ans_max[i]+=ans_max[l];
					break;
				}
			}
			
//			cout << "ans_max[" << i << "]:" << ans_max[i] << " num:" << num[i] << endl;
			
			if(ans_max[i]>=100.0)
			{
				for(int k=0;k<j;k++)
				{
					if(ans[k]==num[i])
						flag=0;
				}
				if(flag==1)
				{
					ans[j]=num[i];
					j++;
				}
			}
		}
		
		if(j!=0)
		{
			for(int i=0;i<j;i++)
			{
				cout << ans[i] << endl;
			}
		}
		else
			cout << "NA" << endl;
	}
}