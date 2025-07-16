#include <iostream>
#include <vector>

using namespace std;
using int_vec = vector<int>;
using Iterator = int_vec::iterator;


Iterator partition(Iterator begin, Iterator end, int x) {
    for (auto it = begin; it != end; ++it) {
        if (*it <= x) {
            swap(*begin++, *it);
        }
    }
    return begin-1;
}


int main() {
    int n;
    cin >> n;

    int_vec v;
    for (auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    auto mid = partition(v.begin(), v.end(), v.back());
    auto it = v.begin();
    for (; it != v.end()-1; ++it) {
        if (it == mid) {
            cout << "[" << *it << "]" << " ";
        } else {
            cout << *it << " ";
        }
    }
    cout << *it << endl;

    return 0;
}