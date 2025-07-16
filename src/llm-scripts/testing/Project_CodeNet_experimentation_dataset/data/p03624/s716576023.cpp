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

    set<char> c;
    for(int i=0;i<26;i++){
        c.insert((char)('a'+i));
    }

    bool ans=true;
    for(int i=0;i<s.size();i++){
        if(c.count(s[i]))c.erase(s[i]);
        if(c.empty())ans=false;
    }

    if(ans){
        auto it = c.begin();
        cout << *it << endl;
    }
    else cout << "None" << endl;

    return 0;
}
