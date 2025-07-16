#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,a,n) for(int i=a;i>=n;i--)
#define INF 999999999
#define INF_M 2147483647
#define pb(a) push_back(a)

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<pii> VP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main() {
    string s;
    while(getline(cin,s)) {
		string t;
		rep(j,0,26) {
			t.clear();
			rep(i,0,s.length()) {
				if('a' <= s[i] && s[i] <= 'z') t += (s[i] + j > 'z') ? (s[i] + j - 26) : (s[i] + j);
				else t += s[i];
			}
			if(t.find("this") != string::npos) break;
			else if(t.find("the") != string::npos) break;
			else if(t.find("that") != string::npos) break;
		}
		cout << t << endl;
	}
    return 0;
}