#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    deque<char> da, db, dc;
    for (char c : sa) {
        da.push_back(c);
    }
    for (char c : sb) {
        db.push_back(c);
    }
    for (char c : sc) {
        dc.push_back(c);
    }
    bool A = true, B = false;
    while(true) {
        if (A) {
            if (da.empty()) {
                cout << "A" << endl;
                return 0;
            }
            if (da.front() == 'b') {
                B = true;
                A = false;
            }
            else if (da.front() == 'c') {
                A = false;
            }
            da.pop_front();
        }
        else if (B) {
            if (db.empty()) {
                cout << "B" << endl;
                return 0;
            }
            if (db.front() == 'a') {
                A = true;
                B = false;
            }
            else if (db.front() == 'c') {
                B = false;
            }
            db.pop_front();
        }
        else {
            if (dc.empty()) {
                cout << "C" << endl;
                return 0;
            }
            if (dc.front() == 'a') {
                A = true;
            }
            else if (dc.front() == 'b') {
                B = true;
            }
            dc.pop_front();
        }
    }
}
