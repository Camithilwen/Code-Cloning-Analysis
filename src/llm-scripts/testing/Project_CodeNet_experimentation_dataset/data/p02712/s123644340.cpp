#include<bits/stdc++.h>
using namespace std;
long long int math(long long int x)
{
	long long int ans;
	ans=x*(x+1)/2;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int ff,n,fv,th,total,totalff,totalfv,totalth,ans;
	cin>>n;
	total= math(n);
	ff=n/15;
	totalff=15*math(ff);
	th=(n/3);
	totalth=3*math(th);
	fv=(n/5);
	totalfv=5*math(fv);
	ans=total-totalfv-totalth+totalff;
	cout<<ans;
}