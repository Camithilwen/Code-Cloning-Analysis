#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int N;
    cin>>N;
    vector<pair<int, int> > red(N), blue(N);
    int a, b;
    rep(i, N){
        cin>>a>>b;
        red[i] = mp(a, b);
    }
    rep(i, N){
        cin>>a>>b;
        blue[i] = mp(a, b);
    }
    sort(red.begin(), red.end(), greater<pair<int, int> >());
    map<int, int> amap;
    int index;
    int tmp;
    int ans = 0;
    for(int i=0;i<N;++i){
        index = -1;
        tmp = -1;
        for(int j=0;j<N;++j){
            if((red[i].fi<blue[j].fi) && (red[i].se<blue[j].se)){
                if(((index==-1) || (tmp > blue[j].se)) && (amap[j]==0)){
                    index = j;
                    tmp = blue[j].se;
                }
            }
        }
        if(index != -1){
            amap[index]++;
            ans++;
        }
    }
    cout<<ans<<endl;
}

