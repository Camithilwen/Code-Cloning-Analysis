#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k, n;
	string s;

	cin >> k >> s;

	n = (long long)(s.length());

	if (k >= n){
		cout << s << endl;
	}
	else{
		cout << s.erase(k) << "..." << endl;
	}

	return 0;
}
