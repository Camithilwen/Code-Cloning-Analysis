#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

ll amari(ll a){
    if(abs(a) % 2 == 0) return 0;
    else return 1;
}

ll sho(ll a){
    if(a<0 && amari(a)==1) return (a / (-2)) + 1;
    else return a / (-2);
}

stack<char> base_min2(ll a){
    stack<char> res;
    if(a == 0){
        res.push('0');
        return res;
    }
    while(true){
        if(a == 1){
            res.push('1');
            break;
        }
        else{
            if(amari(a) == 1){
                res.push('1');
                a = sho(a);
            }
            else if(amari(a) == 0){
                res.push('0');
                a = sho(a);
            }
        }
    }
    return res;
}

int main(void){
    ll n;
    cin >> n;
    stack<char> ans = base_min2(n);
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    return 0;
}