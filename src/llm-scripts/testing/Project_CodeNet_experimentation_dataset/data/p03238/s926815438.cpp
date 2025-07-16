#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// memo  fixed  setprecision(20);
using vvll = vector<vector<ll>>;
ll mod =1e9+7;
/*"itob" int to "N"base */           template<typename TypeInt> string itob(const TypeInt v, int base){static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";string ret;static numeric_limits<TypeInt> t;TypeInt n = v;if (t.is_signed) {if (v < 0) n *= -1;}while (n >= base) {ret += table[n%base];n /= base;}ret += table[n];if (t.is_signed) {if (v < 0 && base == 10) ret += '-';}reverse(ret.begin(), ret.end());return ret;}
/*"chmin" a = MAX*/                  template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
/*"chmax" a = MIN*/                  template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/*"ctoi"  char to int*/              int ctoi(char c) {return c-'0';}
/*"gcd"   MAX Euclidean */           ll gcd(ll a,ll b){if(b==0)return a; return gcd(b,a%b);}
    /*"lcm"   MIN*/                      ll lcm(ll a,ll b){ll g = gcd(a,b);return a/g*b;}
/*"primecheck"If prime,return true.*/bool primecheck(ll n){if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
string  reverserange(string s,ll a,ll b){reverse(s.begin()+a-1,s.begin()+b); return s;}
ll modpow(ll a,ll n, ll mod){ll res = 1;while(n>0){if (n%2==1){res = res * a % mod;}a = a * a % mod;n/=2;}return res;}
int main() {
    int a;
    cin >>a ;
    if(a==1){
        cout<<"Hello World"<<endl;
        return 0;
    }
    int b,bb;
    cin >>b>>bb;
    b+=bb;
    cout<<b<<endl;
}
    

