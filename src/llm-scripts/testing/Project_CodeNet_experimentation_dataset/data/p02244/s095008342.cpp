#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int di[]={-1, 0, 1, 0}, dj[]={0, -1, 0, 1};

bool is_valid(const vector<size_t> &q, size_t r) {
    for (size_t j=0; j<8; ++j)
        if (j!=r && q[j]==q[r])
            return false;

    for (size_t i=0; i<r; ++i) {
        if (q[i]-i == q[r]-r) return false;
        if (q[i]+i == q[r]+r) return false;
    }

    return true;
}

bool solve_equeen(vector<size_t> &q, size_t r=0) {
    if (r == 8) return true;

    if (!~q[r]) {
        for (size_t c=0; c<8; ++c) {
            q[r] = c;
            if (is_valid(q, r))
                if (solve_equeen(q, r+1))
                    return true;
        }
        q[r] = -1;
    } else {
        if (is_valid(q, r))
            if (solve_equeen(q, r+1))
                return true;
    }

    return false;
}

int main() {
    size_t k;
    scanf("%zu", &k);

    vector<size_t> q(8, -1);
    for (size_t i=0; i<k; ++i) {
        size_t r, c;
        scanf("%zu %zu", &r, &c);

        if (~q[r]) return 1;
        q[r] = c;
    }

    solve_equeen(q);

    for (size_t i=0; i<8; ++i)
        for (size_t j=0; j<8; ++j)
            printf("%c%s", q[i]==j? 'Q':'.', j<7? "":"\n");

    return 0;
}