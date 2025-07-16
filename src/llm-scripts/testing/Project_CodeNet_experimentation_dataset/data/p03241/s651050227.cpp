#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> divisor_list(0);
    for (int i = 1; i * i <= M; i++){
        if (M % i == 0){
            divisor_list.push_back(i);
            divisor_list.push_back(M / i);
        }
    }
    sort(all(divisor_list));
    int len = divisor_list.size();
    int ans = 1;
    rep(i,len){
        if (M / divisor_list[i] >= N){
            ans = divisor_list[i];
        }
    }
    cout << ans << endl;
}