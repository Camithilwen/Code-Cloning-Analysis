#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    set<ll> data;
    ll n;
    cin >> n;
    rep(i,0,n){
        ll a;
        cin >> a;
        if(data.count(a)){
            data.erase(a);
        }else{
            data.insert(a);
        }
    }
    cout<<data.size()<<endl;

    

  return 0;
}