#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
 
template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
long long lcm (int a, int b){
    return  (long long) a*b /gcd(a,b);
}

long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }



int collatz(int n){
    int a=n;
    if(a%2 == 0)a/=2;
    else a = a*3+1;
    return a;
}

int main(){
    int R;
    cin >> R;

    if(R<1200)cout << "ABC" << endl;
    else if (R>=1200 && R<2800)cout << "ARC" << endl;
    else cout << "AGC" << endl;

}

