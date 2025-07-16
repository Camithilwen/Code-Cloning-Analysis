#include<iostream>
using namespace std;

int n,res=0;
bool map[20][20];
bool fh[10],fc[10],fl[20],fr[20];

void print()
{
	for(int i=0;i!=8;++i)
	{
		for(int j=0;j!=8;++j)
		{
			if(map[i][j])	cout<<'Q';
			else			cout<<'.';	
		}
		cout<<endl;
	}
}

bool check(int x,int y)
{
	return !(fh[x] || fc[y] || fr[x+y] || fl[x+n-y+1]);
}

void pcfz(int x,int y,bool type)
{
	fh[x]=type; fc[y]=type;
	fr[x+y]=type;
	fl[x+n-y+1]=type;
	map[x][y]=type;
}

void dfs(int r)
{
	if(r==8)		print();
	else if(fh[r])	dfs(r+1);
	else
	{
		for(int i=0;i!=8;++i)
			if(check(r,i))
			{
				pcfz(r,i,1);
				dfs(r+1);
				pcfz(r,i,0);
			}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		int tx,ty;
		cin>>tx>>ty;
		pcfz(tx,ty,1);		
	}
	dfs(0);
	return 0;
}