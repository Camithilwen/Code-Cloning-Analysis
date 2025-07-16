#define	_USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <set>
#include <complex>
using namespace std;
int main(){
	
	int n;
	long long int m;
	while(cin>>n>>m,n!=0&&m!=0){
	
	vector<long long> v(n+1,0);
	vector<long long> s;

	
	for(int i=1;i<=n;i++)
		cin>>v[i];
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				s.push_back(v[i]+v[j]);
			}
		}
	
	
	
	sort(s.begin(),s.end());
	long long ans=0;
		for(int i=0;i<s.size();i++){
	vector<long long>::iterator it=upper_bound(s.begin(),s.end(),m-s[i]);
			if(it!=s.begin()){
				it--;
			ans=max(ans,s[i]+s[it-s.begin()]);
			}
		}
	cout<<ans<<endl;
	}

	
}