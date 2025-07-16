#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int cnt1 = 0, cnt2=0;
    int h_cnt=0;

    rep(i, s.size()){
       if(s[i]=='-'){
           h_cnt++;
           if(h_cnt==1)swap(cnt1, cnt2);
           continue;

       }
       else{
           cnt1++;
       }
    }
    if(h_cnt==0||h_cnt>1){
        out("No");
        return 0;
    }

    if(a==cnt2&&b==cnt1){
        out("Yes");
    }
    else out("No");
}