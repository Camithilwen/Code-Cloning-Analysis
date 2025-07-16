#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1000000000;

int main() {FIN
    
    int t = 0;
    char e;
    vs nm = {"A", "B", "C"};
    vs ply(3);
    vi pos(3, 0);
    cin >> ply[0];
    cin >> ply[1];
    cin >> ply[2];
    
    while (true) {
		if ((int)ply[t].size() == pos[t]) break;
		e = ply[t][pos[t]];
		pos[t]++;
		t = (e - 'a');
	}
    cout << nm[t] << "\n";
    
    return 0;
}
