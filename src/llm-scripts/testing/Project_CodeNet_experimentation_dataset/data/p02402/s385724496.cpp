#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long> v;
    for (int i = 0; i < n; ++i) {
        long x;
        cin >> x;
        v.push_back(x);
    }
    cout << *min_element(v.begin(), v.end()) << " ";
    cout << *max_element(v.begin(), v.end()) << " ";
    cout << accumulate(v.begin(), v.end(), 0L) << "\n";
}