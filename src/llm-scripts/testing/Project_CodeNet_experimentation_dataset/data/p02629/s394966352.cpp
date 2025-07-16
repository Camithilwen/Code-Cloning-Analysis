#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    long long n;
    cin>>n;

    string result="";
    while(n){
        n--;
        result+=(char)('a'+(n%26));
        n/=26;
    }

    reverse(result.begin(),result.end());
    cout<<result<<endl;
}