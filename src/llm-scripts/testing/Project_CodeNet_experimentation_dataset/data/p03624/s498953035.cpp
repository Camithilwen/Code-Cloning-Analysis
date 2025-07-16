#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    vector<int> alpha(26,0);
    REP(i,S.size()){
        alpha[S[i]-'a']++;
    }
    for (char a='a'; a<='z';a++){
        if(alpha[a-'a']==0){
            cout << a << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}