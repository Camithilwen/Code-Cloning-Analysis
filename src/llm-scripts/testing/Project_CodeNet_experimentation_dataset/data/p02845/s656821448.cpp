#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

// doc: https://shibh308.github.io/library/library/lib/classes/modint.cpp.html
template <i64 mod = MOD>
struct ModInt{
    i64 p;

    ModInt() : p(0){}
    ModInt(i64 x){p = x >= 0 ? x % mod : x + (-x + mod - 1) / mod * mod;}

    ModInt& operator+=(const ModInt& y){p = p + *y - ((p + *y) >= mod ? mod : 0); return *this;}
    ModInt& operator-=(const ModInt& y){p = p - *y + (p - *y < 0 ? mod : 0); return *this;}
    ModInt& operator*=(const ModInt& y){p = (p * *y) % mod; return *this;}
    ModInt& operator%=(const ModInt& y){if(y)p %= *y; return *this;}

    ModInt operator+(const ModInt& y) const{ModInt x = *this; return x += y;}
    ModInt operator-(const ModInt& y) const{ModInt x = *this; return x -= y;}
    ModInt operator*(const ModInt& y) const{ModInt x = *this; return x *= y;}
    ModInt operator%(const ModInt& y) const{ModInt x = *this; return x %= y;}

    friend ostream& operator<<(ostream& stream, const ModInt<mod>& x){
        stream << *x;
        return stream;
    }

    friend ostream& operator>>(ostream& stream, const ModInt<mod>& x){
        stream >> *x;
        return stream;
    }

    ModInt& operator++(){p = (p + 1) % mod; return *this;}
    ModInt& operator--(){p = (p - 1 + mod) % mod; return *this;}

    bool operator==(const ModInt& y) const{return p == *y;}
    bool operator!=(const ModInt& y) const{return p != *y;}

    const i64& operator*() const{return p;}
    i64& operator*(){return p;}

};

using mint = ModInt<>;


signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    mint ans = 1;
    vector<int> v(3, 0);
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        int ex = 0;
        for(int j = 0; j < 3; ++j)
            if(v[j] == a[i]){
                ++cnt;
                ex = j;
            }
        ++v[ex];
        ans *= cnt;
    }
    cout << ans << endl;
}
