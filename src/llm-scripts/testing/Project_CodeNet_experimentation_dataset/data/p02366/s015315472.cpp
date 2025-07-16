#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


static const int MAX = 100000;

vector<int> graph[MAX];
vector<bool> discovered(MAX, false);
vector<int> prenum(MAX, 0), parent(MAX, 0), lowest(MAX, 0);
int V, E;
int t = 0;


void dfs(int vertex, int prev)
{
    prenum[vertex] = lowest[vertex] = ++t;
    discovered[vertex] = true;

    for (auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it) {
        if (!discovered[*it]) {
            parent[*it] = vertex;
            dfs(*it, vertex);
            lowest[vertex] = min(lowest[vertex], lowest[*it]);
        } else if (*it != prev) {
            lowest[vertex] = min(lowest[vertex], prenum[*it]);
        }
    }
}


set<int> arts;
void art_points()
{
    dfs(0, -1);

    int num_root_children = 0;
    for (int i = 1; i < V; i++) {
        int p = parent[i];
        if (p == 0)
            num_root_children++;
        else if (prenum[p] <= lowest[i]) {
            arts.insert(p);
        }
    }

    if (num_root_children > 1) {
        arts.insert(0);
    }

    for (auto it = arts.begin(); it != arts.end(); ++it)
        cout << *it << endl;
}


int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    art_points();

    return 0;
}

