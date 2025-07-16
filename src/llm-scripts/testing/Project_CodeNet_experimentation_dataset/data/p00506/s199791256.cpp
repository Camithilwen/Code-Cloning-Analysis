#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    if(N == 2){
        int a, b;
        cin >> a >> b;
        for(int i = 1; i < max(a,b) + 1; ++i){
            if(a%i == 0 && b%i == 0) cout << i << endl;
        }
    }
    else {
        int a, b , c;
        cin >> a >> b >> c;
        for(int i = 1; i < max(a,max(b,c)) + 1; ++i){
            if(a%i == 0 && b%i == 0 && c%i == 0) cout << i << endl;
        }
    }
    return 0;
}
