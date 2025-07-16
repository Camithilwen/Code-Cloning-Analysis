#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<set>
using namespace std;

void itsvgg() 
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
} 

double rolls[301][301][301];


void initialization()
{
		for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			for(int k=0;k<=300;k++)
				rolls[i][j][k]=0.0;
}	

double prob(int n, int x,int y, int z)
{
	double p1=double(x)/double(n),p2=double(y)/double(n),p3=double(z)/double(n);
	double p0=1-p1-p2-p3;
	double k=1;
	if(x>0)
	{	
		if(rolls[x-1][y][z]==0)
			k+=p1*prob(n,x-1,y,z);
		else
			k+=p1*rolls[x-1][y][z];
	}	
	if(y>0)
	{	
		if(rolls[x+1][y-1][z]==0)
			k+=p2*prob(n,x+1,y-1,z);
		else
			k+=p2*rolls[x+1][y-1][z];
	}	
	if(z>0)
	{	
		if(rolls[x][y+1][z-1]==0)
			k+=p3*prob(n,x,y+1,z-1);
		else
			k+=p3*rolls[x][y+1][z-1];
	}	
	//cout<<x<<" "<<1-p0<<endl;

	if(x!=0 || y!=0 || z!=0)
		rolls[x][y][z]=k/(1-p0);
	else 
		rolls[x][y][z]=0;
	return rolls[x][y][z];	 
	
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
    itsvgg();
	initialization();
	int n;
	cin>>n;
	int ones=0,twos=0,threes=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			ones++;
		}
		else if (x==2)
			twos++;
		else
			threes++;
	}
	//cout<<ones<<twos<<threes<<endl;
	
	//cout<<expected[0][0][0];			
	//cout<<ones<<twos<<threes<<endl;
	cout.precision(10);
	cout<<prob(n,ones,twos,threes);
}
