#include <bits/stdc++.h>

template <class T>
T root(std::vector<T>& v, T x) {
    return v[x] - x ? (v[x] = root(v, v[x])) : x;
}

template <class T>
bool same(std::vector<T>& v, T x, T y) { return root(v, x) == root(v, y); }

template <class T>
void unite(std::vector<T>& v, T x, T y) {
    x = root(v, x);
    y = root(v, y);
    if (x != y) v[x] = y;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    std::vector<std::deque<int>> g(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b; a--; b--;
        unite(p, a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    std::map<int, std::deque<int>> sub;
    for (int i = 0; i < n; i++) {
        sub[root(p, p[i])].push_back(i);
    }

    long long a = 0, b = 0, c = 0;
    std::vector<bool> done(n, false), color(n);
    for (auto& s : sub) {
        auto v = s.second;
        if (v.size() == 1) {
            b++;
            continue;
        }
        std::deque<int> q;
        q.push_back(v[0]);
        color[v[0]] = true;
        bool odd = false;
        while (!q.empty()) {
            auto curr = q.front();
            done[curr] = true;
            for (auto to : g[curr]) {
                if (done[to] && color[to] == color[curr]) {
                    odd = true;
                    // break;
                } else if (!done[to]) {
                    q.push_back(to);
                    color[to] = !color[curr];
                }
            }
            q.pop_front();
            // if (odd) break;
        }
        if (odd) a++;
        else c++;
    }
    // std::cout << a << " " << b << " " << c << std::endl;

    std::cout << (a * a + 2 * a * c + 2 * c * c + 2 * n * b - b * b) << std::endl;

    return 0;
}