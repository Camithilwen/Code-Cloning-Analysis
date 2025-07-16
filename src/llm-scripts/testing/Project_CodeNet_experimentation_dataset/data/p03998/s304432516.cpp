#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    vector<string> deck;
    string s;
    for(int i = 0; i < 3; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        deck.push_back(s);
    }
    int idx = 0, nxt = 0;
    while(!deck[idx].empty()) {
        nxt = deck[idx].back()-'a';
        deck[idx].pop_back();   
        idx = nxt;
        // cout << idx << endl;     
    }
    cout << char('A'+idx) << endl;

    return 0;
}
