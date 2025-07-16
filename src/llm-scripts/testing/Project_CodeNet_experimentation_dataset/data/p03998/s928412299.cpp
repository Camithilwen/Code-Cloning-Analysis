#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> S(3);
	for(int i = 0; i < 3; i++) cin >> S[i];

	int i = 0;

	while(S[i].size()){
		char r = S[i][0];
		S[i].erase(S[i].begin());
		i = r - 'a';
	}

	cout << (char)(i + 'A') << endl;

	return 0;
}
