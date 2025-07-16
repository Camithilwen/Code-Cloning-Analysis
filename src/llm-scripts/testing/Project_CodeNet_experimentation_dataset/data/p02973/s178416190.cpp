#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

u64 N;
vector<u64> a, parent, visited;

void findpath(u64 i){
        if (parent[i] != -1) {
            findpath(parent[i]);
        }
        visited[i] = 1;
        cout << a[i] << endl;
}

bool cmp(u64 a, u64 b){
    return a >= b;
}

int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    vector<u64> M, indexer;
    a.resize(N), parent.resize(N, -1), visited.resize(N, 0);
    for (u64 i = 0; i < N; i++) {
        cin >> a[i];
    }
    M.push_back(a[0]);
    indexer.push_back(0);
    for (auto it = a.begin() + 1; it != a.end(); it++) {
        if (*it <= M.back()) {
            M.push_back(*it);
            parent[it - a.begin()] = indexer.back();
            indexer.push_back(it - a.begin());
        } else {
            auto location = lower_bound(M.begin(), M.end(), *it, cmp);
            *location = *it;
            if (location != M.begin()) {
                parent[it - a.begin()] = indexer[location - M.begin() - 1];
            }
            indexer[location - M.begin()] = it - a.begin();
        }
    }
    
    cout << M.size() << endl;
    //findpath(indexer.back());
    
    
    
    
    return 0;
}
