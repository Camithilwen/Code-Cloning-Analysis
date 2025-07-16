#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 





int main(void){
    ll n;
    string s;
    cin>>n;
    cin>>s;
    ll ans = 1;
    ll num = 0;
    for(ll i=0;i<2*n;i++){
        if((2*n-1-i)%2==1){
            if(s[i]=='B')num++;
            else{
                ans = ans*num;
                ans = ans%N;
                num--;
            }
        }
        else{
            if(s[i]=='W')num++;
            else{
                ans = ans*num;
                ans = ans%N;
                num--;
            }
        }
    }
    if(num!=0){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        ans = ans*i;
        ans = ans%N;
    }
    cout<<ans<<endl;
    return 0;
}

