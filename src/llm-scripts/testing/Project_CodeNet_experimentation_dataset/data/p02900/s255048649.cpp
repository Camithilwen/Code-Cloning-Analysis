#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
map<T,T> fact(T n){
    map<T,T> Map;
    for(T i = 2; i * i <= n; i++){
        while(n % i == 0){
            Map[i]++;
            n /= i;
        }
    }
    if(n == 1)return Map;
    Map[n]++;
    return Map;
}


int main()
{
    ll a, b;
    cin >> a >> b;
    ll gc = gcd(a, b);
    cout << fact(gc).size() + 1 << endl;
}