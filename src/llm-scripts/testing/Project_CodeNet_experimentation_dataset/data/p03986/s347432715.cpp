// https://atcoder.jp/contests/agc005/tasks/agc005_a
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    string X;
    cin >> X;
    int N = X.size();

    stack<char> st;
    for (int i = 0; i < N; ++i)
    {
        // 見ている文字とスタックの先頭に着目する
        if ('S' == X[i])
        {
            st.push('S');
        }
        else // 'T' == X[i]
        {
            if (st.empty())
            {
                st.push('T');
                continue;
            }
            
            char c = st.top();
            if (c == 'T')
            {
                st.push('T');
            }
            else // c == 'S'
            {
                st.pop();
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}
