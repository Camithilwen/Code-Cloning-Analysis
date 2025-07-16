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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll num[110][8];

int main(){
    int H,W,k;
    ll ans;
    cin>>H>>W>>k;
    num[0][0]=1;
    bool f=true;
    for(int i=1;i<8;i++) num[0][i]=0;
    for(int h=1;h<=H;h++){
        for(int w=0;w<(1<<(W-1))-1;w++){
            for(int i=0;i<W-1;i++){
                if(w>>i & 1  &&  w>>(i+1) & 1) f=false;   
            }
            if(f){
                int v[]={0,1,2,3,4,5,6,7};
                for(int i=0;i<W-1;i++){
                    if(w>>i & 1){
                        v[W-1-i]--;
                        v[W-1-i-1]++;
                    }
                }
                for(int i=0;i<8;i++){
                    num[h][i]+=num[h-1][v[i]];
                    num[h][i]%=MOD;
                }
            }
            f=true;
        }
    }
    if(W==1){
        ans=1;
    }else{
        ans=num[H][k-1];
    }
    cout<<ans<<endl;
    return 0;
}