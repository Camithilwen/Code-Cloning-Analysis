#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define BIL ((ll)1e9)
#define MOD ((ll)1e9+7)
#define INF (1LL<<60)           //1LL<<63でオーバーフロー
#define inf (1<<29)             //1<<29でオーバーフロー

int main(int argc,char* argv[]){
    string s;
    cin >> s;

    bool ans=true,ccheck=false;
    for(int i=0;i<s.size();i++){
        if(i==0){
            if(s[i]!='A'){
                ans=false;
                break;
            }
        }else if(i>=2 && i<=s.size()-2 && s[i]=='C'){
            if(ccheck){
                ans = false;
                break;
            }else{
                ccheck=true;
            }
        }else{
            if(isupper(s[i])){
                ans=false;
                break;
            }
        }
    }

    if(ans && ccheck)cout << "AC" << endl;
    else cout << "WA" << endl;

    return 0;
}
