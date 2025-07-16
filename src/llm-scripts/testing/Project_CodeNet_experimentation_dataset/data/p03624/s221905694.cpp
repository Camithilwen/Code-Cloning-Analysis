#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {

	string S;
	cin >> S;

    bool a[26];
    for (int i = 0; i < 26 ; ++i) a[i] = false;

    for (int i = 0; i < S.size(); ++i) {
        a[S[i] - 'a'] = true;
    }

    for (int i = 0; i < 26; ++i) {
        if (!a[i]) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
    
    cout << "None" << endl;
    return 0;

}
