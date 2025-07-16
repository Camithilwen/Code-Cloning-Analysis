#include<bits/stdc++.h>
#define int long  long 

using namespace std ;
                                                                                                  
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;
                                                                                                                                       
    int n ; 
    cin >> n ; 
    string s ; 
    cin >> s ;
    set<int> b ; 
   	for(int i = 0 ; i< n  ; ++i)
  	{	
   		if(s[i] == 'B')
   			b.insert(i); 	
   	}
	int cnt = 0 ;
	int v = b.size() ; 
	for(int i = 0; i < n ; ++i)
	{
		if(s[i] == 'R')
		{
			for(int j = 0; j < n ; ++j)
			{
				if(s[j] == 'G')
				{
					int d = abs(i-j) ; 
					int temp = 0 ; 
					if(b.find(i - d) != b.end())
						temp++ ; 
					if(b.find(i + d) !=  b.end())
						temp++ ; 
					if(b.find(j - d) != b.end())
						temp++ ; 
					if(b.find(j + d) !=  b.end())
						temp++ ;
					if(d%2 == 0 && b.find(min(i,j) + d/2) != b.end())
						temp++ ;
					cnt += v - temp ; 	 

				}
			}
		}
	}
   	cout << cnt ;
                                                                                                                                       
}
                                      




