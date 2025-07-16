#include <iostream>
#include <vector>

using namespace std;

int dfs(auto& nodes, int current_index, int parent_index, int& time) {
    int children = 0;
    
    auto& current_node = nodes[current_index];
    current_node.time = time;
    current_node.low = time;
    
    for (auto adjacent_index : current_node.adjacent) {
        if (adjacent_index == parent_index) {
            continue;
        }
        
        auto& adjacent_node = nodes[adjacent_index];
        if (adjacent_node.time) {
            current_node.low = min(adjacent_node.time, current_node.low);
        } else {
            ++children;
            dfs(nodes, adjacent_index, current_index, ++time);
            
            if (current_node.time <= adjacent_node.low) {
                current_node.is_articulation_point = true;
            }
            
            current_node.low = min(adjacent_node.low, current_node.low);
        }
    }
    
    return children;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    if (n == 0 || m == 0) {
        return 0;
    }
    
    struct node {
        int time{0};
        int low{0};
        bool is_articulation_point{false};
        vector<int> adjacent;
    };
    
    vector<node> nodes(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        nodes[from].adjacent.push_back(to);
        nodes[to].adjacent.push_back(from);
    }
    
    int time = 0;
    nodes[0].is_articulation_point = dfs(nodes, 0, -1, ++time) > 1;
    
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i].is_articulation_point) {
            cout << i << endl;
        }
    }
    
    return 0;
}
