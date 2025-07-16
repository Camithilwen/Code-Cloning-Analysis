#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9


int main() {
    int N, L;
    cin >> N >> L;
    vector<int> abs_taste(N);
    int eat = 300;
    int c;
    for (int i = 0; i < N; i++)
    {
        abs_taste[i] = abs(L + i);
        if(abs_taste[i] < eat){
            eat = abs_taste[i];
            c = i;
        }
    }
    int sum = N * (L - 1) + (1 + N) * N / 2;
    int ans = sum - (L + c );
    cout << ans << endl;
    
}