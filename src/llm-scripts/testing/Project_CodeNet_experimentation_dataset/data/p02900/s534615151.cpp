#include <bits/stdc++.h>
using namespace std;

int prime_factors(long long x){
    set<int>s;
    if(x%2 == 0){
        s.insert(2);
        while(x%2 == 0){
            x /= 2;
        }
    }
    for(int i = 3; i <= sqrt(x); i++){
        if(x%i == 0){
            s.insert(i);
            while(x%i == 0){
                x/= i;
            }
        }
    }
    if(x > 1){
        s.insert(x);
    }
    
    return s.size();
    
}


int main(){
    
    long long a, b;
    cin >> a >> b;
    long long g = __gcd(a, b);
    
    long long factors = prime_factors(g);
    
    cout << factors + 1 << endl;
}
