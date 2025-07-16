#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int time = 0;
    if(h1==h2){
        time += m2-m1;
        cout << time -k << endl;
    }
    else{
        time += 60 - m1;
        //cout << time << endl;
        time += m2;
        //cout << time << endl;
        time += (h2 - (h1 + 1))*60;
        cout << time - k << endl;
    }
    return 0;
}