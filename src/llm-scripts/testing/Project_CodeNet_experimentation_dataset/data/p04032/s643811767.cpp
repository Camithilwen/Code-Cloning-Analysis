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

	string S;
	cin >> S;

	vector<vector<int>> Oc(27);

	for(int i = 0; i < S.size(); i++){
		Oc[S[i] - 'a'].pb(i);
	}

	bool can = 0;

	for(int i = 0; i < 27; i++){
		for(int l = 0; l < Oc[i].size(); l++){
			for(int r = l + 1; r < Oc[i].size(); r++){
				if(r - l + 1 > (Oc[i][r] - Oc[i][l] + 1)/2){
					can = 1;
					cout << Oc[i][l] + 1 << " " << Oc[i][r] + 1 << endl;
				}
				if(can) break;
			}
			if(can) break;
		}
		if(can) break;
	}

	if(!can){
		cout << -1 << " " << -1 << endl;
	}

	return 0;
}
