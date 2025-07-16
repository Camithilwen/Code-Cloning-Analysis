#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void Yes()
{
    puts("Yes");
    exit(0);
}

void No()
{
    puts("No");
    exit(0);
}

// 1-indexed BIT (i : [1, len])
template<typename T>
struct BIT : std::vector<T>
{
    BIT(int len = 0) : std::vector<T>(len + 1) {}
    void reset() { fill(this->begin(), this->end(), 0); }
    void add(int pos, T v) {
        while (pos > 0 and pos < (int)this->size()) (*this)[pos] += v, pos += pos & -pos;
    }
    T sum(int pos) const { // (0, pos]
        T res = 0;
        while (pos > 0) res += (*this)[pos], pos -= pos & -pos;
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i < (int)bit.size(); i++) {
            T now = bit.sum(i);
            os << now - prv << ",";
            prv = now;
        }
        os << ']';
        return os;
    }
};

vector<int> parity(vector<int> V)
{
    int N = 1e5;
    BIT<int> bit(N);
    vector<int> ret(V.size() * 2 - 1);
    lint ten = 0;
    REP(i, V.size()) {
        int dest = (V[i] - 1);
        ret[dest * 2] += abs(dest - i);
        // if (i) {
        //     // int nb_empty = i - bit.sum(i);
        //     // ret[i * 2 - 1] += nb_empty;
        // }
        ten += bit.sum(N) - bit.sum(V[i]);
        bit.add(V[i], 1);
    }
    ret[1] += ten % 2;
    // dbg(V);
    // dbg(ret);
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(3, vector<int>(N));
    cin >> A;
    vector<vector<int>> val(2);
    vector<int> inv;
    REP(i, N) {
        REP(d, 2) if (abs(A[d][i] - A[d + 1][i]) != 1) No();
        int invtmp = 0;
        if (A[0][i] > A[2][i]) invtmp = 1;
        int tmp = min(A[0][i], A[2][i]) / 3;
        if (abs(tmp - i) % 2) No();
        val[i % 2].emplace_back(tmp / 2 + 1), inv.emplace_back(invtmp);
    }
    // dbg(val);
    vector<int> v1 = parity(val[0]);
    vector<int> v2 = parity(val[1]);
    REP(i, v1.size()) inv.at(i) ^= v1.at(i) % 2;
    REP(i, v2.size()) inv.at(i + 1) ^= v2.at(i) % 2;
    // dbg(inv);
    vector<int> cou(4);
    REP(i, N) cou[i % 4] ^= inv[i];
    // dbg(cou);
    int tot = accumulate(cou.begin(), cou.end(), 0);
    if (tot % 4 == 0) Yes();
    if (tot % 2) No();
    if (tot % 4 == 0 or (cou[0] ^ cou[2]) == 0) Yes();

    No();
}
