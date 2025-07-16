#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long int ll;


int main()
{
	ll N,T;
	cin>>N>>T;
	ll sum = T * N;
	ll *t = new ll[N];
	cin>>t[0];
	for(int i = 1; i < N; i++){
		cin>>t[i];
		if( T > (t[i] - t[i-1])){
			ll deltaT = t[i] - t[i-1];
			sum -= (T - deltaT);
		}
	}
	cout<<sum<<endl;
	return 0;
}

