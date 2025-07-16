#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int a[26];

int main(){
    string s;cin >> s;
    REP(i,s.size()){
        int num = s[i]-'a';
        a[num]++;
    }
    if(s.size()!=26){
        cout << s;
        REP(i,26){
            if(a[i]==0){
                COUT((char)('a'+i));
                break;
            }
        }
    }
    else{
        string past = s;
        do{
            if(s>past){
                for(int i=0;i<26;i++){
                    if(s[i]==past[i])cout << s[i];
                    else{
                        COUT(s[i]);
                        return 0;
                    }
                }
            }
        }while(next_permutation(s.begin(),s.end()));
        COUT(-1);
    }
    return 0;
}