#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

string ten[3]={"A","B","C"};

int main()
{
	int n;
	cin>>n;
	for(;n!=0;cin>>n)
	{
		rep(i,n)
		{
			int ma,en,ja;
			int ans=2;
			cin>>ma>>en>>ja;
			
			if(((ma+en+ja)/3>=50&&(ma>=80||en>=80))||(ma+en+ja)/3>=70)ans=1;
			if((ma+en+ja)/3>=80||(ma+en)/2>=90||en==100||ja==100||ma==100)ans=0;
			
			cout<<ten[ans]<<endl;
		}
		
		
	}
}