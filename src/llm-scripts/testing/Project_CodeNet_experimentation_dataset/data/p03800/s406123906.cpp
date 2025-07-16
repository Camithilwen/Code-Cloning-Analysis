#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e5;
int a[N];
int info[N];
bool check_feasibility(int n)
{
	for(int i = 2; i < n; i++)
		a[i] = a[i-2]^a[i-1]^info[i-1];
	if((a[n-2]^a[n-1]^a[0])!=info[n-1] || (a[n-1]^a[0]^a[1])!=info[0])
		return false;
	else
		return true;
}
bool solve(int n)
{
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
		{
			a[0] = i;
			a[1] = j;
			if(check_feasibility(n))
				return true;
		}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		char c; cin >> c;
		info[i] = c=='x';
	}
	if(solve(n))
	{
		for(int i = 0; i < n; i++)
			cout<<(a[i] ? "W" : "S");
		cout<<endl;
	}
	else
		cout<<-1<<endl;
	
	cout<<flush;
	return 0;
}