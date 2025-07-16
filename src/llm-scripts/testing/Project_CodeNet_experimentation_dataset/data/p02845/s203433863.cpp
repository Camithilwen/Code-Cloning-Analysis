#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll color1 = 0;
    ll color2 = 0;
    ll color3 = 0;
    ll count = 1;
    rep(i,N){
        if (color1 == A[i] && color2 == A[i] && color3 == A[i]){
            color1++;
            count = (count * 3) % 1000000007;
        }
        else if (color1 == A[i] && color2 == A[i]){
            color1++;
            count = (count * 2) % 1000000007;
        }
        else if (color2 == A[i] && color3 == A[i]){
            color2++;
            count = (count * 2) % 1000000007;
        }
        else if (color1 == A[i]) color1++;
        else if (color2 == A[i]) color2++;
        else if (color3 == A[i]) color3++;
        else{
            count = 0;
        }
    }
    cout << count << endl;
}
