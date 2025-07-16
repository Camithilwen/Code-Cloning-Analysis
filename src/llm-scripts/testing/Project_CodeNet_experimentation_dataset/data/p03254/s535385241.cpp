#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, x;
    vector<int> A;
    int ans = 0;
    cin >> N >> x;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i)
    {
        if (A[i] > x){
            break;
        }
        x -= A[i];
        ++ans;
    }
    if (x > 0 && ans == N){
        ans -= 1;
    }
    cout << ans << endl;
}