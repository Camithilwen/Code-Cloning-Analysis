#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<sstream>
#include<queue>
#include<deque>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#define INF 2147483647
#define lli long long int
#define MOD 1000000007

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;


//A???65 a???97
int main() {
	vector<char> eki(52);
	eki[0] = 65;
	eki[26] = 97;
	for (int i = 1; i < 26; i++){
		eki[i] = eki[i-1] + 1;
		eki[26+i] = eki[26+i-1] + 1;
	}

	while(1){
		int n; cin >> n;
		if (n == 0) break;
		vi key(n);
		for (int i = 0; i < n; i++){
			cin >> key[i];
		}

		string station; cin >> station;
		string ans = "";
		for (int i = 0; i < station.size(); i++){
			if (isupper(station[i])){
				ans += eki[(station[i]-'A'-key[i%n]+52)%52];
			}else{
				ans += eki[(station[i]-'a'+26-key[i%n]+52)%52];
			}
		}
		cout << ans << endl;

	}

	return 0;
}