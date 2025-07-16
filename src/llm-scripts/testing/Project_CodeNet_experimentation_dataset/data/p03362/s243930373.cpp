#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<bool> vec(55555);
    vec[1] = false;
    for (int i = 2; i <= 55554; i++){
        vec[i] = true;
    }
    for(int i = 2; i <= 55554; i++){
        if (vec[i]){
            for (int j = 2; j * i <= 55554; j++){
                vec[i * j] = false;
            }
        }
    }
    vector<int> ans(0);
    for (int i = 1; i <= 55551; i += 5){
        if (vec[i]) ans.push_back(i);
    }
    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
}