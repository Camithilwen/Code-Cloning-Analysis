#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll powll(ll b, int e) {
    ll result = 1;
    while (e) {
        if (e & 1) {
            result *= b;
        }
        b *= b;
        e >>= 1;
    }
    return result;
}

bool is_palindrome(const string &s) {
    int N = s.size();
    int i = 0;
    int j = N - 1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

ll count_palindromes(string s, bool is_inner) {

    int L = s.size();

    if (L == 0) {
        return 1;
    }

    if (L == 1) {
        int n = stoi(s);
        if (is_inner) {
            return n + 1;
        } else {
            return n;
        }
    }

    string t = s.substr(1, L - 2);
    int a = stoi(s.substr(0, 1));
    int b = stoi(s.substr(L - 1, 1));

    ll result = 0;

    if (!is_inner) {
        for (int k = 1; k < L; ++k) {
            result += 9 * powll(10, (k - 1) / 2);
        }
    }

    if (is_inner) {
        result += a * powll(10, (L - 1) / 2);
    } else {
        result += (a - 1) * powll(10, (L - 1) / 2);
    }

    if (is_inner || a > 0) {
        result += count_palindromes(t, true);
        if (a > b) {
             if (is_palindrome(t)) {
                --result;
            }
        }
    }

    return result;
}

ll count_palindromes(ll n) {
    if (n) {
        return count_palindromes(to_string(n), false);
    } else {
        return 0;
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int result = count_palindromes(B) - count_palindromes(A - 1);
    cout << result << endl;

    return 0;
}