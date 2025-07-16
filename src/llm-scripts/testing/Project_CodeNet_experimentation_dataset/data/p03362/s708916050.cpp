#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;

    vector<bool> P(56000, true);
    P[0] = false;
    P[1] = false;
    for (int i = 2; i < 250; i++) {
        if(P[i] == false){
            continue;
        }
        else{
            for (int j = i; i * j < 56000; j++) {
                P[i * j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i < 56000; i+=5) {
        if(P[i] == true){
            ans.push_back(i);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

}