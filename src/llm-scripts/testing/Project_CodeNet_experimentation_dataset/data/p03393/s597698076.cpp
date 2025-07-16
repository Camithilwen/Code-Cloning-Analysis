#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
const double PI = 3.1415926535;

int main() {
   string s;
   cin >> s;
   int n = s.size();
   vector<int>cnt(26,0);
   if(n!=26){
       rep(i, 0, n){
           cnt[s[i]-'a']++;
       }
       //cout << "ok" << endl;
       rep(i, 0, 26){
           if(cnt[i]==0){
               char t = i + 'a';
               cout << s << t << endl;
               return 0;
           }
       }
   }else if (s!="zyxwvutsrqponmlkjihgfedcba"){
       string s2 = s;
       string p;
       next_permutation(s.begin(),s.end());
       while(s>s2){
           p = s[s.size()-1];
           s.erase(s.size()-1);
       }
       cout << s << p << endl;
   }else{
       cout << -1 << endl;
   }
}