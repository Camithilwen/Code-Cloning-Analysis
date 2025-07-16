#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
#include <chrono>
#include<unordered_map>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef tuple<int, int, int> TIII;
typedef vector<int> VI;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int MN = 1e9;

int main()
{
    fast_io();

    map<PII, int> M;

    int N;
    scanf("%d", &N);
    REP(i, N)
    {
        double A;
        scanf("%lf", &A);
        LL llA = llround(A * MN);

        // wylicz ile zawieraja 2 i 5
        int x = 0, y = 0;
        while (llA % 2 == 0)
        {
            x++;
            llA /= 2;
        }
        while (llA % 5 == 0)
        {
            y++;
            llA /= 5;
        }

        x = min(x, 18), y = min(y, 18);
        M[MP(x, y)]++;
    }

    LL res = 0;
    // zobacz ile jest par, ktore maja sume x >= 0 i sume y >= 0
    for (const auto &p : M)
    {
        if (p.first.first >= 9 && p.first.second >= 9)
            res += p.second*(LL)(p.second - 1) / 2;

        auto it = M.find(p.first); it++;
        while (it != M.end())
        {
            if (p.first.first + it->first.first >= 18 && p.first.second + it->first.second >= 18)
                res += p.second*(LL)it->second;

            it++;
        }
    }

    printf("%lld\n", res);

    return 0;
}

// FOR GNU C++ use the following pattern:
// Uncomment the code below and change your main into main2
// It does not build in MS C++
// But it does increase the stack size from 256 MB on CF and uses GNU C++

//#include <Processthreadsapi.h>
//#include <iostream>
//#include <Synchapi.h>
//#include <windows.h>
//#include <process.h>
//
//DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
//    main2(nullptr);
//    return 0;
//}
//int main() {
//    auto h = CreateThread(nullptr, 1024 << 20, MyThreadFunction, nullptr, STACK_SIZE_PARAM_IS_A_RESERVATION, nullptr);
//    WaitForSingleObject(h, INFINITE);
//}