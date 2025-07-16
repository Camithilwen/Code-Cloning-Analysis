#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

size_t isort(vector<int> &A, size_t g) {
    size_t count_=0;
    for (size_t i=g; i<A.size(); ++i) {
        int v=A[i], j;
        for (j=i-g; j>=0&&v<A[j]; j-=g) {
            A[j+g] = A[j];
            ++count_;
        }
        A[j+g] = v;
    }
    return count_;
}

size_t shsort(vector<int> &A) {
    size_t count_=0;
    size_t m=A.size();

    vector<size_t> g; g.push_back(1);
    for (size_t h=4; h<=m&&g.size()<100; ++(h*=3))
        g.push_back(h);

    reverse(g.begin(), g.end());

    printf("%zu\n", g.size());
    for (size_t i=0; i<g.size(); ++i)
        printf("%zu%c", g[i], i<g.size()-1? ' ':'\n');

    for (size_t d: g)
        count_ += isort(A, d);

    return count_;
}

int main() {
    size_t N;
    scanf("%zu", &N);

    vector<int> A(N);
    for (size_t i=0; i<N; ++i)
        scanf("%d", &A[i]);

    size_t t=shsort(A);

    printf("%zu\n", t);
    for (size_t i=0; i<N; ++i)
        printf("%d\n", A[i]);

    return 0;
}