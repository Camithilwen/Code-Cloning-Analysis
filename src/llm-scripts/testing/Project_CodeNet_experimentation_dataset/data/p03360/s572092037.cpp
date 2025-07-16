#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    vector<int> list(3);
    int K;
    for (int i = 0; i < 3; i++)
        cin >> list[i];
    cin >> K;
    sort(list.begin(), list.end());
    cout << list[2] * pow(2, K) + list[1] + list[0];
}