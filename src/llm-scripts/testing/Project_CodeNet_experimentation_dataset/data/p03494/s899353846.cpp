#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n,0);
	int ans = 1000000000;
	for(int i = 0; i < n; i ++){
		int num;
		cin>>num;
		int localAns = 0;
		while( num % 2 == 0){
			num /= 2;
			localAns++;
		}
		ans = min(localAns,ans);
	}
	cout<<ans<<endl;
	return 0;
}

