#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int numa[1000000], numb[1000000];
int main(){
    int n; cin >> n;
    vector<int> a, b;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
        numa[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        b.push_back(y);
        numb[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if(numa[i]+numb[i] > n) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = 1; i <= n; i++)
    {
        numa[i] += numa[i-1];
        numb[i] += numb[i-1];
    }
    int shift=0;
    for (int i = 1; i <= n; i++)
    {
        shift = max(shift, numa[i] - numb[i-1]);
    }
    for(int i = 0; i < n; i++){
        cout << b.at((i+n-shift)%n) << " ";
    }
    puts("");
}