#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
/*!* [intutil] *!*/
/*+* 整数演算いろいろ *+*/
i64 divceil(i64 a, i64 b) {
    return a / b + (a > 0 && a % b ? 1 : 0);
}
i64 logceil(i64 a, i64 b) {
    for(i64 i = 0, x = 1; a >= 2; x *= a, i++) if(x <= b) return i; return 0;
}
i64 gcd(i64 a, i64 b) {
    for (i64 c; a;) c = a, a = b % a, b = c; return b;
}
i64 lcm(i64 a, i64 b) {
    return (a / gcd(a, b) * b);
}
int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(i64 &a : A) cin >> a;
    bool ans;
    // i : ターン数 (0 mod 2 で自分のターン)
    for(int i = 0; true; i++) {
        i64 g = A[0];
        for(i64 a : A) g = gcd(g, a);
        for(i64 &a : A) a /= g;
        
        int even_num = 0;
        for(i64 a : A) even_num += (a % 2 == 0);
        if(even_num % 2) { // 偶数が奇数個
            ans = i % 2 == 0;
            break;
        } else { // 偶数が偶数個
            i64 odd = 0;
            for(i64 a : A) if(a % 2 == 1) odd = a; 
            if(N - even_num == 1 && odd > 2) { // 奇数が一つだけで、それは1でない
                for(i64 &a : A) if(a % 2 == 1) a--;
                continue;
            } else {
                ans = i % 2 == 1;
                break;
            }
        }
    }
    cout << (ans ? "First" : "Second") << endl;
    return 0;
}