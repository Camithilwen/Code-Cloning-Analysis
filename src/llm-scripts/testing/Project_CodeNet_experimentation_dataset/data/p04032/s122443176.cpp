#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple


int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	string s; cin>>s;
	int len=s.length();
	map <char,int> mp;
	map <char,int> pp;
	int st=-1,en=-1;
	for(int i=0;i<len;i++)
	{
	    mp[s[i]]++;
	    if(mp[s[i]]==1) pp[s[i]]=i;
	    else
	    {
	        if( i-pp[s[i]] <= 2 )
	        {    
	            st=pp[s[i]]+1; en=i+1;
	            break;
	        }
	        pp[s[i]]=i;
	    }
	}
	cout<<st<<' '<<en;
	
	
	return 0;
}
