#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

const int MOD = (int)1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    REP(i, N) {
        cin >> vec.at(i);
    }

    // 偶数indで、一番多いものに合わせる
    map<int, int> even_map;
    for(int i = 0; i < N; i+=2) {
        int val = vec[i];

        if (even_map.count(val) == 1) {
            even_map[val] += 1;
        } else {
            even_map[val] = 1;
        }
    }

    // 奇数indで、一番多いものに合わせる
    map<int, int> odd_map;
    for(int i = 1; i < N; i+=2) {
        int val = vec[i];

        if (odd_map.count(val) == 1) {
            odd_map[val] += 1;
        } else {
            odd_map[val] = 1;
        }
    }

    int odd_most_freq = -1;
    int odd_most_freq_cnt = 0;

    int odd_2nd_most_freq;
    int odd_2nd_most_freq_cnt = 0;

    for (auto x : odd_map){
        int key = x.first;
        int value = x.second;

        if (value > odd_most_freq_cnt) {
            odd_2nd_most_freq = odd_most_freq;
            odd_2nd_most_freq_cnt = odd_most_freq_cnt;

            odd_most_freq = key;
            odd_most_freq_cnt = value;
        } else if (value > odd_2nd_most_freq_cnt) {
            odd_2nd_most_freq = key;
            odd_2nd_most_freq_cnt = value;
        }
    }

    int even_most_freq = 0;
    int even_most_freq_cnt = 0;


    int even_2nd_most_freq;
    int even_2nd_most_freq_cnt = 0;
    for (auto x : even_map){
        int key = x.first;
        int value = x.second;
        debug(key);
        debug(value);

        if (value > even_most_freq_cnt) {
            even_2nd_most_freq = even_most_freq;
            even_2nd_most_freq_cnt = even_most_freq_cnt;

            even_most_freq = key;
            even_most_freq_cnt = value;
        } else if (value > even_2nd_most_freq_cnt) {
            even_2nd_most_freq = key;
            even_2nd_most_freq_cnt = value;
        }
    }

    // REP(i, N) {
    //     int v = vec.at(i);
    //     debug(v);
    // }

    debug(even_most_freq);
    debug(even_most_freq_cnt);
    debug(even_2nd_most_freq);
    debug(even_2nd_most_freq);

    debug(odd_most_freq);
    debug(odd_most_freq_cnt);
    debug(odd_2nd_most_freq);
    debug(odd_2nd_most_freq);

    int evens = N % 2 == 0 ? (N / 2) : (N+1) / 2;
    debug(evens);

    int ans_even = evens - even_most_freq_cnt;
    debug(ans_even);

    int odds = N / 2;
    debug(odds);

    int ans_odd = odds - odd_most_freq_cnt;
    debug(ans_odd);

    if (even_most_freq == odd_most_freq) {
        int a = odds - odd_2nd_most_freq_cnt + ans_even;
        int b = evens - even_2nd_most_freq_cnt + ans_odd;

        int c = a < b ? a : b;
        cout << c << endl;

        return 0;
    }

    cout << ans_even + ans_odd << endl;
}
