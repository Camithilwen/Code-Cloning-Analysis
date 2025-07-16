#include <iostream>
#include <stack>
using namespace std;

long long N;
void input()
{
    cin >> N;   
}

void solve()
{
    long long num = 0;
    long long t26[13]; long long n26 = 1;
    for (int i = 0; i < 13; ++i) { t26[i] = n26; n26 *= 26; }
    long long tborder[13]; tborder[0] = 0;
    for (int i = 1; i < 13; ++i) tborder[i] = tborder[i-1] + t26[i];

    for (int i = 0; i < 13; ++i){
        // cout << tborder[i] << " ";
        if (tborder[i] < N) continue;
        N -= tborder[i-1] + 1;
        stack<char> stk;
        while (i != 0){
            stk.push('a' + N % 26);
            N /= 26;
            --i;
        }
        while (!stk.empty()){
            cout << stk.top(); 
            stk.pop();
        }
        cout << endl;
        break;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}