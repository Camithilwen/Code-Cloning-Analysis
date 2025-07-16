    #include <bits/stdc++.h>
    using namespace std;
    #define all(x) (x).begin(), (x).end()
    #define SZ(X) ((int)(X).size())
    #define endl "\n";
    int main()
    {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	// freopen("input.txt", "r", stdin);
    	// freopen("output.txt", "w", stdout);
    	string s,a;
    	cin>>s;
    	set<char> t(all(s));
    	a = "abcdefghijklmnopqrstuvwxyz";
    	
    	for (auto c:a)
    	{
    		auto pos =t.find(c);
    		if(pos==t.end()){
    			cout<<c;	
    			return 0;
    		}
    		
    	}
    cout<<"None";
     
       return 0;
    }