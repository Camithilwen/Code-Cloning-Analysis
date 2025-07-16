#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace util {
    template<typename T >
    void print_vector(vector<T> &v) {
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it;
            if (it + 1 != v.end())
                cout << " ";
        }
        cout << endl;
    }
}

namespace {
    void insertion_sort(vector<int> &a, int g, int &count) {
        for (int i = g; i < a.size(); i++) {
            int v = a[i];
            int j = i - g;
            while (j >= 0 && a[j] > v) {
                a[j+g] = a[j];
                j = j - g;
                count++;
            }
            a[j+g] = v;
        }
    }

    vector<int> shell_sort(vector<int> &a, int &count) {
        vector<int> gs;
        int g = 1;
        while (a.size() >= g) {
            gs.push_back(g);
            g = 3 * g + 1;
        }

        reverse(gs.begin(), gs.end());

        for (int _g : gs) {
            insertion_sort(a, _g, count);
        }

        return gs;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    int count = 0;

    vector<int> gs = shell_sort(v, count);

    cout << gs.size() << endl;
    util::print_vector(gs);
    cout << count << endl;
    for(int i : v) {
        cout << i << endl;
    }
    return 0;
}