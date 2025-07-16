#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	ll A,B,M,t;
	vector<ll>AA,BB,ANS;
	cin>>A>>B>>M;
	rep(i,A){
		cin>>t;
		AA.push_back(t);
	}
	rep(i,B){
		cin>>t;
		BB.push_back(t);
	}
	rep(i,M){
		ll x,y,z,zz;
		cin>>x>>y>>z;
		zz=AA[x-1]+BB[y-1]-z;
		ANS.push_back(zz);
	}
	sort(AA.begin(),AA.end());
	sort(BB.begin(),BB.end());
	ANS.push_back(AA[0]+BB[0]);
	sort(ANS.begin(),ANS.end());
	cout<<ANS[0]<<endl;
}