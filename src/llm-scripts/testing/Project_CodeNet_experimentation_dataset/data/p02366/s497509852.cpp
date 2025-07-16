#include <iostream>
#include <vector>
#include <set>
using namespace std;

static const int NIL = -1;

struct Vertex {
    vector<int> link;
    int parent = NIL;
    int ord;
    int lowlink;
    bool is_visit = false;
};

class ArticulationPoint {
private:
    int n;
    vector<Vertex> graph;
    int timer = 1;

public:
    ArticulationPoint() {}

    ArticulationPoint(int n)
    {
        this->n = n;
        graph.resize(n);
        int edge;
        cin >> edge;
        int s, t;
        for (int e = 0; e < edge; e++)
        {
            cin >> s >> t;
            graph[s].link.push_back(t);
            graph[t].link.push_back(s);
        }
    }

    void dfs(int current)
    {
        graph[current].is_visit = true;
        graph[current].ord = graph[current].lowlink = timer;
        timer++;

        for(int next : graph[current].link)
        {
            if(!graph[next].is_visit)
            {
                graph[next].parent = current;
                dfs(next);
                graph[current].lowlink = min(graph[current].lowlink, graph[next].lowlink); // 3.
            }
            else if(next != graph[current].parent)
            {
                // １回の移動で行くことのできる訪問済みの頂点は，Backedgeを除けば自分の親しかいない
                // つまりこのブロックにくるのはnextがBackedgeを通った訪問済みの頂点のとき
                graph[current].lowlink = min(graph[current].lowlink, graph[next].ord);
            }

        }
    }

    void articulation_point()
    {
        set<int> art_point;
        int root = 0;

        dfs(root);

        int root_child_num = 0;
        for(int u = 0; u < n; u++)
        {
            int p = graph[u].parent;
            if(p == NIL) continue;
            if(p == root)
            {
                root_child_num++;
                if(root_child_num >= 2)
                    art_point.insert(root);
            }
            else if(graph[p].ord <= graph[u].lowlink)
            {
                art_point.insert(p);
            }
        }

        for(int x : art_point)
            cout << x << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    ArticulationPoint articulationPoint(n);
    articulationPoint.articulation_point();
}
