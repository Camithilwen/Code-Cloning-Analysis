#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

template <class RandomIt>
RandomIt partition_(RandomIt first, RandomIt last) {
    using T=typename RandomIt::value_type;
    T x=last[-1];
    RandomIt it=first-1;
    for (RandomIt it2=first; it2<last-1; ++it2)
        if (*it2 <= x) {
            ++it;
            swap(*it, *it2);
        }

    swap(*++it, last[-1]);
    return it;
}

int main() {
    size_t n;
    scanf("%zu", &n);

    vector<int> A(n);
    for (size_t i=0; i<n; ++i)
        scanf("%d", &A[i]);

    vector<int>::iterator pivot=partition_(A.begin(), A.end());
    for (vector<int>::iterator it=A.begin(); it<pivot; ++it)
        printf("%d ", *it);

    printf("[%d] ", *pivot);

    for (vector<int>::iterator it=pivot+1; it<A.end(); ++it)
        printf("%d%c", *it, it<A.end()-1? ' ':'\n');

    return 0;
}