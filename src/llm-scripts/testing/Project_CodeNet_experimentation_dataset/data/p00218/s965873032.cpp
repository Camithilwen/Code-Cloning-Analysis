#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

char school(int m, int e, int j)
{
if( m == 100 || e == 100 || j == 100 )
        return 'A';
    if( (m+e)>=180 || (m+e+j)>=240)
        return 'A';
    if( (m+e+j)>=210 || ( (m+e+j)>=150 && (m>=80||e>=80) ) )
		return 'B';
	else
    return 'C';
}
int main()
{
	int x, m, e, j;
	while(cin>>x)
	{
		for(int i=0; i<x; i++)
		{
			cin>>m>>e>>j;
			
		
		cout<<school(m,e,j)<<endl;
		}
	}
	
	return 0;
}