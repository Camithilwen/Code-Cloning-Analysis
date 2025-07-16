#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define inf             1e18
#define no_of_test(x)        int x; cin>>x; while(x--)
const int mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	no_of_test(x)
	{
      int n;
	  cin>>n;
	  int a[n];
	  set<int>s;
	  for(int i=0;i<n;i++)
	  {
		  cin>>a[i];
		  s.insert(a[i]);
	  }
	  if(s.size()==n)
	  {
		  cout<<"YES"<<'\n';
	  }
	  else
	  {
		cout<<"NO"<<'\n';
	  }
	  

	}
	return 0;
}