#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    loop(i,n){
        cin >> v[i];
    }

    ll result = 0;

    // i個の宝石を取る
    loop(i,min(n,k)+1){
        // j個だけ左から取る
        loop(j,i+1){
            vector<int> minusJewel = {};
            ll tmp = 0; 
            loop(l,j){
                tmp += v[l];
                if(v[l] < 0)minusJewel.push_back(v[l]);
            }
            loop(l,i-j){
                tmp += v[n-1-l];
                if(v[n-l-1] < 0)minusJewel.push_back(v[n-l-1]);
            }
            sort(minusJewel.begin(),minusJewel.end());
            ll minusNum = minusJewel.size();
            
            loop(l,min(k-i, minusNum)){
                tmp -= minusJewel[l];
            }
        
            result = max(tmp, result);
        }
    }

    cout << result << endl;
}