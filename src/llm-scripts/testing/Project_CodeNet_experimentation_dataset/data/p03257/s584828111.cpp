#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define NMAX 502
#define DIM 7920

int d[DIM], p[DIM];
long long sol[NMAX][NMAX];

void ciur(int n) {
    for (int i = 2; i <= n; i++) {
        if (d[i] == 0) {
            p[++p[0]] = i;
            for (int j = i + i; j <= n; j += i) {
                d[j] = 1;
            }
        }
    }
}

__int128 gcd(__int128 a, __int128 b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

__int128 lcm(vector <long long>& v) {
    __int128 l = 1;
    for (const long long x : v) {
        if (x == 0)
            continue;
        __int128 d = gcd(l, (__int128)x);
        l = l * x / d;

    }
    return (long long)l;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 2) {
        cout << "4 7\n23 10\n";
        return 0;
    }
    ciur(DIM - 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sol[i][j] = 1;
        }
    }

    int cnt = 1;
    for (int j = 1; j <= n; j += 2) {
        int col = j;
        for (int i = 1; i <= n; i++) {
            if (col > n)
                break;
            sol[i][col] *= p[cnt];
            col++;
        }
        cnt++;
    }

    for (int i = 3; i <= n; i += 2) {
        int lin = i;
        for (int j = 1; j <= n; j++) {
            if (lin > n)
                break;
            sol[lin][j] *= p[cnt];
            lin++;
        }
        cnt++;
    }

    for (int j = 1; j <= n; j += 2) {
        int col = j;
        for (int i = 1; i <= n; i++) {
            if (col <= 0)
                break;
            sol[i][col] *= p[cnt];
            col--;
        }
        cnt++;
    }

    for (int i = n; i > 1; i -= 2) {
        int lin = i;
        for (int j = n; j >= 1; j--) {
            if (lin > n)
                break;
            sol[lin][j] *= p[cnt];
            lin++;
        }
        cnt++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0)
                continue;
            vector <long long> v = {sol[i - 1][j], sol[i + 1][j], sol[i][j - 1], sol[i][j + 1]};
            sol[i][j] = lcm(v) + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
