#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define upto(f, t, i)    for(decltype(t) _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(decltype(t) _##i = (t), i = (f); i < _##i; i++)
#define downto(f, t, i)  for(decltype(t) _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(decltype(t) _##i = (t), i = (f); i > _##i; i--)
#define unless(c) if(!(c))
#define until(c) while(!(c))
#define loop while(true)

#define all(v) v.begin(), v.end()
#define ln << "\n"

struct line{};

template<class T> istream& operator>>(istream& in, vector<T>& v) {
    times(v.capacity(), i) in >> v[i];
    return in;
}

template<class T> const ostream& operator<<(ostream& out, const vector<T>& v) {
    times(v.size(), i) out << (i ? " " : "") << v[i];
    return out;
}

template<class T, class...U> typename enable_if<is_same<T, line>::value, string>::type next(istream& in, const U&... args) {
    string s;
    getline(in, s, args...);
    return move(s);
}

template<class T, class...U> typename enable_if<!is_same<T, line>::value, T>::type next(istream& in, const U&... args) {
    T t(args...);
    in >> t;
    return move(t);
}
template<class T, class...U> auto next(const U&... args) -> decltype(next<T>(cin)) {
    return next<T>(cin, args...);
}

template<class T> T sum(const vector<T>& v) {
    T ans = T();
    for(const T& t : v) ans += t;
    return ans;
}

template<class T> T sum(const typename vector<T>::iterator& begin, const typename vector<T>::iterator& end) {
    T ans = T();
    for(typename vector<T>::iterator t = begin; t != end; t++) ans += *t;
    return ans;
}

template<class T> T min(const vector<T>& v) {
    return *min_element(v.begin(), v.end());
}

template<class T> T min(const typename vector<T>::iterator& begin, const typename vector<T>::iterator& end) {
    return *min_element(begin, end);
}

template<class T> T max(const vector<T>& v) {
    return *max_element(v.begin(), v.end());
}

template<class T> T max(const typename vector<T>::iterator& begin, const typename vector<T>::iterator& end) {
    return *max_element(begin, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto N = next<int>();
    vector<int> point(N, 0);
    times(N * (N - 1) / 2, i) {
        auto A = next<int>() - 1, B = next<int>() - 1, C = next<int>(), D = next<int>();
        if(C > D) {
            point[A] += 3;
        } else if(C < D) {
            point[B] += 3;
        } else {
            point[A]++;
            point[B]++;
        }
    }
    vector<int> point_(N, 0), rank(N);
    times(N, i) point_[i] = point[i];
    sort(all(point_), greater<int>());
    int p_ = 0;
    #ifdef debug
        times(N, i) cout << point[i] ln;
        cout ln;
        times(N, i) cout << point_[i] ln;
        cout ln;
    #endif
    times(N, i) {
        int p = point_[i];
        if(p == p_) continue;
        p_ = p;
        times(N, j) {
            if(p == point[j]) {
                rank[j] = i + 1;
            }
        }
    }
    times(N, i) cout << rank[i] ln;

    return 0;
}