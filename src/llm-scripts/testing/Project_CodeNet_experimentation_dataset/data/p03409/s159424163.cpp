#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
#define F first 
#define S second
#define PB push_back 
#define MP make_pair
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    int N;
    cin >> N;
    vp r(N),b(N);
    rep(i,N) cin >>r[i].F>>r[i].S;
    rep(i,N) cin >>b[i].F>>b[i].S;
    vi left(N,0);
    vi max(N,0);

    sort(all(b));
    sort(all(r));

    int jj=0;
    int ans=0;
    rep(i,N){//ao
        bool judge=false;
        rep(j,N){//aka
            if(left[j] ==0){
                if(r[j].F<b[i].F && r[j].S<b[i].S && r[j].S>=max[i]){
                    max[i]=r[j].S;
                    jj = j;
                    judge = true;
                }
            } 
        }
        if(judge) {
            ans++;
            left[jj] = 1;
        }
    }
    cout <<ans<<endl;
}