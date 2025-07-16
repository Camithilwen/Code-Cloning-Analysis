#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int n = a; n <= b; n++) {
        if (n / 10000 == n % 10 && (n / 1000) % 10 == (n / 10) % 10) {
            cnt ++;
        }
    }
    put(cnt);
    return 0;
}