
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>

#include <algorithm>
#include <complex>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
#endif

#define ITER(c)         __typeof__((c).begin())
#define FOREACH(it, c)  for (ITER(c) it=(c).begin(); it != (c).end(); ++it)
#define RITER(c)        __typeof__((c).rbegin())
#define RFOREACH(it, c) for (RITER(c) it=(c).rbegin(); it != (c).rend(); ++it)
#define REP(i, n)       REPEAT(i, 0, n)
#define REPEAT(i, k, n) for (int i = (k); i < (n); ++i)
#define REVREP(i, n)    for (int i = ((n)-1); i >= 0; --i)
#define FIND(c, n)      std::find((c).begin(), (c).end(), (n));
#define BSEARCH(c, n)   std::binary_search((c).begin(), (c).end(), (n))
#define LLPOW(p1,p2)    ((ll)pow((double)(p1), (int)p2))
#define ESIZEOF(A)      (sizeof(A)/sizeof((A)[0]))
#define MIN(p1,p2)      (((p1)<(p2))?(p1):(p2))
#define MAX(p1,p2)      (((p1)>(p2))?(p1):(p2))
#define CIN_NO_SYNC     do { cin.tie(0); ios_base::sync_with_stdio(false); } while(0)
#define GETSTR(p)       fgets((p), sizeof(p), stdin)
#define CHOMP(p)        do{ char *_q = (p) + strlen(p)-1; if(*_q == '\n') *_q = 0; } while(0)

typedef long long ll;
typedef unsigned long long ull;

#ifdef _DEBUG
#define pf printf
#define pr(n) do { cout << #n " = " << (n) << endl; } while(0)
#else
#define pf(...) /* */
#define pr(...) /* */
#endif

namespace roman {
struct romantbl_t {
    const char *rom;
    int num;
} table[] = {
    { "M",  1000,   },
    { "CM", 900,    },
    { "D",  500,    },
    { "CD", 400,    },
    { "C",  100,    },
    { "XC", 90,     },
    { "L",  50,     },
    { "XL", 40,     },
    { "X",  10,     },
    { "IX", 9,      },
    { "V",  5,      },
    { "IV", 4,      },
    { "I",  1,      },
};

map<int,string> num2rom;
map<string,int> rom2num;

void romaninit(){
    for(int i = 0; i < sizeof(table)/sizeof(table[0]); i++){
        rom2num.insert(make_pair(table[i].rom, table[i].num));
        num2rom.insert(make_pair(table[i].num, table[i].rom));
    }
}

int roman2num(string rom){
    int len = rom.length();
    int t = 0, p = 0;
    for(int i = len - 1; i >= 0; i--){
        string c = rom.substr(i,1);
        int n = rom2num[c];
        if(n < p){ t -= n; } else { t += n; }
        p = n;
    }
    return t;
}

string num2roman(int num){
    string t;
    for(int i = 0; i < sizeof(table)/sizeof(table[0]); i++){
        int n = table[i].num;
        while(num >= n){
            t += num2rom[n]; num -= n;
        }
    }
    return t;
}
}

using namespace roman;

int main(){
    string s;
    romaninit();
    while(getline(cin, s)){
        cout << roman2num(s) << endl;
    }
    return 0;
}