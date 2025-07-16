#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	int p,q,r,sum,maxm;
	cin >> p >> q >> r;
	sum = p + q + r;
	maxm = max({p,q,r});
	cout << sum - maxm; 

	
	
}	
