#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int p,q,r,a,b;
 	cin>>p>>q>>r;
	a=min(p+q,q+r);
	b=min(a,p+r);
	cout<<b<<endl;
	return 0;
}
 	
 					