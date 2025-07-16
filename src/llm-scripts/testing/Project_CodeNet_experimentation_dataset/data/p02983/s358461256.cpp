#include <iostream>
#include<algorithm>
#include<utility>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;

int main() {
    int l, r;
    cin>>l>>r;
    int mx = min(2018,r-l);
    int ans = 9999;
    for(int i = l+mx; i > l; i--){
        for(int j = l; j < i; j++){
            ans = min(ans,((i%2019)*(j%2019))%2019);
        }
    }
    cout<<ans<<endl;

    return 0;
}