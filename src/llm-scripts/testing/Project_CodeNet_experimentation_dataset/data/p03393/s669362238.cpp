#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    string s; cin >> s;
	int n = s.size();
	if(s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
		return 0;
	}
	if(n != 26) {
		for(char a = 'a'; a <= 'z'; a++) {
			if(count(s.begin(), s.end(), a) == 0) {
				cout << s << a << endl;
				return 0;
			}
		}
	}
	string k = s;
	next_permutation(k.begin(), k.end());
	for(int i = 0; i < n; i++){
		if(s[i] != k[i]) {
			cout << k.substr(0, i + 1) << endl;
            system("pause");
			return 0;
		}
	}

    system("pause");
}