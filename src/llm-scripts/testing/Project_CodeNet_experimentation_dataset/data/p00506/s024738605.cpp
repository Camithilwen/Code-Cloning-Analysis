#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
using ll = long long;

ll gcd(ll a, ll b){
    //cout << "a : " << a << "b : " << b << endl;
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main(){
    int n;
    cin >> n;
    set<int>  s;
    if (n == 2){
        ll a, b;
        cin >> a >> b;
        ll g = gcd(a, b);
        for (int i = 1; i <= sqrt(g); i++){
            if(g % i==0){
                s.insert(i);
                s.insert(g / i);
            }
        }
        for (auto itr = s.begin(); itr != s.end(); itr++){
            cout << *itr << endl;
        }
    }else{
        ll a, b, c;
        cin >> a >> b >> c;
        ll g = gcd(a, b);
        //cout << g << endl;
        g = gcd(g, c);
        //cout << g << endl;
        for (int i = 1; i <= sqrt(g); i++)
        {
            if(g % i==0){
                s.insert(i);
                s.insert(g / i);
            }
        }
        for (auto itr = s.begin(); itr != s.end(); itr++){
            cout << *itr << endl;
        }
    }
    return 0;
}
