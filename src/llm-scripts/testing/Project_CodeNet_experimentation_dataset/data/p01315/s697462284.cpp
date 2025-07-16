#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
 
using namespace std;



int main(){

	int n;
	while(cin>>n,n){

		map<long double,set<string> > ans;
		for(int i=0;i<n;i++){
			string name;
			long double p,a,b,c,d,e,f,s,m;
			cin>>name>>p>>a>>b>>c>>d>>e>>f>>s>>m;
			ans[((f*s*m)-p)/(a+b+c+m*(d+e))].insert(name);
		}

		for(auto it=ans.rbegin();it!=ans.rend();it++){
			set<string> ss =it->second;
			for(auto it2=ss.begin();it2!=ss.end();it2++) cout<<(*it2)<<endl;
			
		}
		cout<<"#"<<endl;
	}

	return 0;
}