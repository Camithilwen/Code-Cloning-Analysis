#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(n==2){
        if(s[0]==s[1])cout<<"1 2"<<endl;
        else cout<<"-1 -1"<<endl;
        return 0;
    }
    rep(i,n-1){
        string t = s.substr(i,3);
        if(t[0]==t[1]||t[1]==t[2]||t[0]==t[2]){
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1<<endl;
}