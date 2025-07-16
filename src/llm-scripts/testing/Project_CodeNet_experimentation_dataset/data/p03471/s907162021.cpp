#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    int n,y;
    cin>>n>>y;
    int ans[]={-1,-1,-1};
    bool f=true;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j<=n){
                int k=n-i-j;
                int val=i*10000+j*5000+1000*k;
                if(val==y){
                    ans[0]=i;
                    ans[1]=j;
                    ans[2]=k;
                    f=false;
                    break;
                }
            }
        }
        if(!f) break;
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    

}