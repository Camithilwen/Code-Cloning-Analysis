#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

queue<char>q[3];


void scan(int n)
{
	char c;
	while((c=getchar() )!='\n')
		{
			q[n].push(c);
		}
}
int main()
{
    fast;
    
    scan(0);
    scan(1);
    scan(2);
    

	ll k=0;
	while(!q[k].empty())
	{
		char c=q[k].front();
		q[k].pop();
		
		k=c-'a';
	}
	

  cout<<char(k +'A');
  
    
   
}

		
	
	
	
	
