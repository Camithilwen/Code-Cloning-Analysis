#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
class StrongDisassembly{

    private:
        ll V;
        vector<vector<ll>> E;
        vector<vector<ll>> inv_E;
        ll *number;
        bool *used_dfs;
        ll to_write_num = 0;

        void dfs(ll now){
            used_dfs[now] = 1;
            for(ll next : E[now]){
                if(used_dfs[next]){
                    continue;
                }
                dfs(next);
            }
            number[now] = to_write_num++;
        }

        void dfs(ll now, bool *used, vector<ll> &ret){
            used[now] = 1;
            ret.push_back(now);
            for(ll next : inv_E[now]){
                if(used[next]){
                    continue;
                }
                dfs(next, used, ret);
            }
        }

        void write_num(){
            for(ll i = 0; i < V; i++){
                if(!used_dfs[i]){
                    dfs(i);
                }
            }
        }

    public:
        StrongDisassembly(const vector<vector<ll>> &e){
            V = e.size();
            E = e;
            inv_E = vector<vector<ll>>(V);
            number = new ll[V];
            used_dfs = new bool[V];
            for(ll i = 0; i < V; i++){
                used_dfs[i] = 0;
                inv_E.push_back(vector<ll>(0));
            }
            for(ll i = 0; i < V; i++){
                for(ll next : e[i]){
                    inv_E[next].push_back(i);
                }
            }
            write_num();
        }

        map<ll, vector<ll>> disassembly(){
            map<ll, vector<ll>> ret;
            vector<ll> vec;
            bool used[V] = {};
            for(ll i = 0; i < V; i++){
                vec.push_back(i);
            }
            sort(vec.begin(), vec.end(), [&](ll a, ll b){
                    return number[a] > number[b];
                    }
                );
            for(ll vertex : vec){
                if(used[vertex]){
                    continue;
                }
                vector<ll> to_insert;
                dfs(vertex, used, to_insert);
                ret[ret.size() - 1] = to_insert;
            }
            return ret;
        }
};
int main(){
    ll V, E;
    cin >> V >> E;
    vector<vector<ll>> v(V);
    for(ll i = 0; i < E; i++){
        ll s, t;
        cin >> s >> t;
        v[s].push_back(t);
    }
    StrongDisassembly S(v);
    auto ret = S.disassembly();
    map<ll, ll> group;
    for(auto ite = ret.begin(); ite != ret.end(); ite++){
        for(ll u : ite->second) group[u] = ite->first;
    }
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i++){
        ll u, v;
        cin >> u >> v;
        cout << (group[u] == group[v] ? 1 : 0) << endl;
    }
    return 0;
}
