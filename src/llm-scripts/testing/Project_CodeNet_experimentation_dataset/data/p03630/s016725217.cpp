#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
int main()
{
	int h,w;
	cin>>h>>w;
	int a[h+1][w+1];
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			char c;cin>>c;
			a[i][j]= c=='#';
		}
	}

	int b[h][w];



	for(int i=1;i<h;i++)
	{
		for(int j=1;j<w;j++)
		{
			int k=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];

			b[i][j]= k%2==0;
		
		}
	
	}


	int ht[w+1]={};
    int next[w+1];
    int prev[w+1];
    int ans=max(h,w);
	for(int i=1;i<h;i++)
	{
		for(int j=1;j<w;j++)
		    ht[j]=(b[i][j]==1)? ht[j]+1: 0;

        
		ht[w]=ht[0]=-1;
		

	    stack<int> st;
	    st.push(0);
        
	    for(int j=1;j<w;j++)
	    {
	    	while(ht[st.top()]>=ht[j])st.pop();
	    	prev[j]=st.top();
	    	st.push(j);
	    }
	    while(!st.empty())st.pop();
	    
	    st.push(w);
	    
	    for(int j=w-1;j>0;j--)
	    {
	    	while(ht[st.top()]>=ht[j])st.pop();
	    	next[j]=st.top();
	    	st.push(j);
	    }
        
	    for(int j=1;j<w;j++)
	    {
	    	ans=max(ans,(ht[j]+1)*(next[j]-prev[j]));
	    }

	}
	cout<<ans<<endl;
	return 0;
}