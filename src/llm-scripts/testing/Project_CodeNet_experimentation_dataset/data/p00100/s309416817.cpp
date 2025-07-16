#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        
        std::vector<unsigned int> v;
        std::map<unsigned int, unsigned long long int> m;
        
        unsigned int a;
        unsigned long long int b, c;
        for (int i = 0; i < n; ++i) {
            scanf("%u %llu %llu", &a, &b, &c);
            v.push_back(a);
            m[a] += b * c;
        }
        
        std::set<unsigned int> dup;
        bool found = false;
        for (auto i : v) {
            if (m[i] >= 1000000 && dup.count(i) == 0) {
                printf("%u\n", i);
                dup.insert(i);
                found = true;
            }
        }
        if (!found) {
            printf("NA\n");
        }
    }
}