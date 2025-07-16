#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

int n,m;
vector<int> came;
string str[11];
set<string> ans;

void serch(int loop,string sans)
{
//	cout << "loop:" << loop << endl;
	if(loop==m)
	{
//		cout << "came:" ;
//		for(int i=0;i<came.size();i++)
//			cout <<  came[i] << " " ;
//		cout << endl;
//		cout << sans << endl;;
		ans.insert(sans);
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<came.size();j++)
		{
//				cout << "j:" << j << " now:" << came[j] << " size:" << came.size() << " " << i << endl;
			if(i==came[j])
			{
				i++;
				j=-1;
			}
		}
		if(i==n)
			break;
//		cout << "next:" << i << endl;
		came.push_back(i);
		serch(loop+1,sans+str[i]);
		came.pop_back();
	}
	return ;
}

int main()
{
	int i,j;
	for(;;)
	{
		cin >> n >> m ;
		if(n==0 && m==0)
			break;
		
		ans.clear();
		
		for(i=0;i<n;i++)
			cin >> str[i] ;
		
		serch(0,"");
		
		cout << ans.size() << endl;
	}
}