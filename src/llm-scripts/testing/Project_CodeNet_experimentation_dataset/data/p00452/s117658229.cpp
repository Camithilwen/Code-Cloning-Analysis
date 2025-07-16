#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n, m;

    while (scanf("%lld %lld", &n, &m), n){
        long long p[1024];

        for (int i = 0; i < n; i++) scanf("%lld", p + i);
        p[n++] = 0;

        vector<long long> score;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!binary_search(score.begin(), score.end(), p[i] + p[j])) score.push_back(p[i] + p[j]);
            }
        }
        sort(score.begin(), score.end());
        score.erase(unique(score.begin(), score.end()), score.end());

        long long maxi = 0;
        for (auto i : score){
            if (i > m) continue;
            maxi = max(maxi, min(*(upper_bound(score.begin(), score.end(), m - i) - 1) + i, m));
        }

        printf("%lld\n", maxi);
    }

    return 0;
}