#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;

	if(s.length()==3)
	{
		reverse(s.begin(),s.end());
	}

	cout << s << '\n';
	
	return 0;
}