#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 998244353;
const i64 INF = 998244353;

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

auto mpow = [](auto x, i64 y){
    auto z = x;
    decltype(x) val = y & 1 ? x : decltype(x)(1);
    while(z *= z, y >>= 1)
        if(y & 1)
            val *= z;
    return val;
};




signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> v;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ++v[a[i]];
    }
    if(a[0] != 0 || v[0] != 1){
        cout << 0 << endl;
        return 0;
    }
    int ma = *max_element(a.begin(), a.end());

    mint ans = 1;
    for(int i = 1; i <= ma; ++i){
        if(v[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        ans *= mpow(mint(v[i - 1]), v[i]);
    }
    cout << ans << endl;
}
