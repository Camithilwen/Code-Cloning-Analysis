#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef long long LL;
typedef double T;
typedef pair<T,T> P;

double pi;
// difference
P operator-(const P& lhs, const P& rhs)
{
	return P(lhs.first-rhs.first,lhs.second-rhs.second);
}

P operator+(const P& lhs, const P& rhs)
{
	return P(lhs.first+rhs.first, lhs.second+rhs.second);
}

P full(0,1);
P one(1,1);
P f(P a, P b)
{
	if(a==full){
		return b;
	}
	if(a.first+0.5<b.first){
		b=b-one;
	}
	if(b.first+0.5<a.first){
		a=a-one;
	}
	P r=P(max(a.first,b.first),min(a.second,b.second));
	if(r.first<0){
		r=r+one;
	}
	return r;
}
P ps[100];
int main(){
	pi=atan2(0,-1);
    long long N;
    scanf("%lld",&N);
    for(int i = 0 ; i < N ; i++){
		double x,y;
        scanf("%lf",&x);
        scanf("%lf",&y);
		ps[i]=P(x,y);
    }

	for(int i=0;i<N;i++){
		P r=full;
		bool zero=false;
		for(int j=0;j<N;j++){
			if(i==j)continue;
			auto v=ps[j]-ps[i];
			auto c=atan2(v.second,v.first)/(2*pi);
			P p(c-0.25,c+0.25);
			while(p.first<0){
				p=p+one;
			}
			r=f(r,p);
			//cerr << i << ", " << j << ": " << p.first << ", " << p.second << ": " << r.first << ", " << r.second << ": " << v.first << ", " << v.second << ": " << c << endl;
			//cerr << atan2(v.second,v.first) << ", " << pi << endl;
			if(r.first>=r.second){
				zero=true;
				break;
			}
		}
		if(zero){
			cout << 0 << endl;
		}
		else{
			cout << r.second-r.first << endl;
		}
	}

    return 0;
}
