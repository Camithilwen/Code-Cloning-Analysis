#include <cstdio>
#include <set>
#include <vector>

using namespace std;

inline int abs(int x) { return (x >= 0) ? x : - x; }

int main()
{
    int n;
    long d;
    scanf("%d%ld", &n, &d);
    vector<long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%ld", &a[i]);

    vector<long> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] + i * d;

    set<pair<long, int>> pairs;
    for (int i = 1; i < n; i++)
        pairs.insert(make_pair(b[i], i));

    long cost = 0;
    int j = 0;
    int k = 0;
    while (!pairs.empty()) {
        const int i = pairs.begin()->second;
        cost += abs(i - j) * d + a[i] + a[j];
        pairs.erase(pairs.begin());
        for (k++; k < i; k++) {
            cost += min(abs(i - k) * d + a[i] + a[k], abs(j - k) * d + a[j] + a[k]);
            pairs.erase(make_pair(b[k], k));
        }
        if (a[i] < a[j] + abs(i - j) * d)
            j = i;
    }

    printf("%ld\n", cost);

    return 0;
}
