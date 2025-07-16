#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

string ABCD;

bool isEnd = false;

void dfs(int total, string signs, int index){
    if (isEnd) return;
    if(index == 4){
        if (total == 7){
            string ans = "";
            ans += ABCD[0];
            for (int i = 0; i < 3; i++){
                ans += signs[i];
                ans += ABCD[i+1];
            }
            cout << ans+"=7" << endl;
            isEnd = true;
        } 
        return;
    }
    dfs(total+(ABCD[index]-'0'), signs+"+", index+1);
    dfs(total-(ABCD[index]-'0'), signs+"-", index+1);
    
}

int main(){
    cin >> ABCD;

    dfs(ABCD[0]-'0', "", 1);
}