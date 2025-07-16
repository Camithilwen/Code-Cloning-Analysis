//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    vector<int> v(26,0);
    for(auto ch:s) v[ch-'a']=1;
    rep(i,26){
        if(v[i]==0){
            cout<<(char)('a'+i)<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
}
