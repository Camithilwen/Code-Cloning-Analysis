// g++ -std=c++11 test.cpp && ./a.out
// g++ -std=c++11 test.cpp && cat test.txt | ./a.out

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>

using namespace std;

#define INF (1<<29)
#define SZ(X) ((int)(X).size())
#define PRINT(A) {for (auto it=A.begin(); it != A.end(); ++it) {cout << *it << ' ';} cout << endl;}
#define SUM(A) accumulate(A.begin(), A.end(), 0)
#define MAX(A) *max_element(A.begin(), A.end())
#define BIT_LENGTH(N) floor(log2(N)) + 1
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = N-1; I >= 0 ; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RREPP(I, A, B) for (int I = A; I > (B); --I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;

void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }

const double PI = acos(-1);
const int MAX_SIZE = 2*1e5+1;
VI A_indexes[MAX_SIZE];

int main() {
    int N;
    _R(N);
    // cout << N << endl;
    VI C(N+1, 0);
    VI A;
    REP(i, N) {
        int a;
        _R(a);
        A.push_back(a);
        C[a] += 1;
    }
    VI B;
    REP(i, N) {
        int b;
        _R(b);
        B.push_back(b);
        C[b] += 1;
    }

    REP(i, N+1) {
        if (C[i] > N) {
            puts("No");
            return 0;
        }
    }

    reverse(B.begin(), B.end());
    int swap_index = 0;
    REP(i, N) {
        if (A[i] == B[i]) {
            while (A[i] == A[swap_index] || B[i] == B[swap_index]) {
                swap_index += 1;
            }
            swap(B[swap_index], B[i]);
            swap_index += 1;
        }
    }
    puts("Yes");
    PRINT(B);

    return 0;
}