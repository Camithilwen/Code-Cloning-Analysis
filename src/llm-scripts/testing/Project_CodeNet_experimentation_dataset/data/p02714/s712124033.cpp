#include <iostream>
#include <string>
using i64 = long long;

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    i64 cnt[3] {};
    for (auto c : s) cnt[c == 'R' ? 0 : c == 'G' ? 1 : 2]++;

    i64 ret = cnt[0] * cnt[1] * cnt[2];
    for (int i = 0; i < n; i++) for (int j = 1; i - j >= 0 && i + j < n; j++) {
        if (s[i] != s[i - j] && s[i] != s[i + j] && s[i - j] != s[i + j]) ret--;
    }

    std::cout << ret << std::endl;

    return 0;
}
