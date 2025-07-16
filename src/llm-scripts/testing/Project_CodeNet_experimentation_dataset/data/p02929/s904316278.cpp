#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

const int MOD = 1e9+7;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    int ok = 1;
    vector<ll> A(2*N);
    A[0]=1;
    //L==1,R==0
    for(int i=1;i<2*N;i++){
        if(S[i]!=S[i-1])A[i]=A[i-1];
        else A[i]=1-A[i-1];
    }
    if(A[2*N-1]==1)ok = 0;
    if(S[0]=='W'&&S[2*N-1]=='W')ok=0;
    int num = 0;
    ll res = 1;
    for(int i=2*N-1;i>=0;i--){
        if(A[i]==0)num++;
        else{
            res*=num;
            res%=MOD;
            num--;
        }
    }
    if(num!=0)ok=0;
    ll facN = 1;
    for(int i=1;i<=N;i++){
        facN*=i;
        facN%=MOD;
    }
    if(ok)cout << (res*facN)%MOD << endl;
    else cout << 0 << endl;
    return 0;
}