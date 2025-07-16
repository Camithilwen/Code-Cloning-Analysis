#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int n = s.size();

	rep(i, n - 1){
		if(s.substr(i, 2) == "AC"){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
}
