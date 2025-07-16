#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000001
int U,V;
int dist_toU;
struct node{
    vector<int> to;
    int dist;
    bool path_toU;
    node(){
        dist=0;
        path_toU=false;
    }
};
void dfs1(int v, int p, vector<node> &nodes){
    for (int i = 0; i < nodes[v].to.size(); i++){
        int v_to=nodes[v].to[i];
        if(v_to==p)continue;
        nodes[v_to].dist=nodes[v].dist+1;
        if(v_to==U){
            nodes[v_to].path_toU=true;
            dist_toU=nodes[v_to].dist;
        }
        dfs1(v_to, v, nodes);
        if(nodes[v_to].path_toU)nodes[v].path_toU=true;
    }
    for (int i = 0; i < nodes[v].to.size(); i++){
        int v_to=nodes[v].to[i];
        if(v_to==p)continue;
        nodes[v].dist=max(nodes[v].dist,nodes[v_to].dist);
    }
}

int main() {
    int N;
    cin>>N;
    cin>>U>>V;U--;V--;
    vector<node> nodes(N);
    for (int i = 0; i < N-1; i++){
        int A,B;
        cin>>A>>B;A--;B--;
        nodes[A].to.push_back(B);
        nodes[B].to.push_back(A);
    }
    dist_toU=0;
    dfs1(V,-1,nodes);
    int move=dist_toU/2+1;
    int ans=0;
    int v=V,p=-1;
    while(move>0){
        for(int v_to:nodes[v].to){
            if(v_to==p)continue;
            if(nodes[v_to].path_toU){
                p=v;
                v=v_to;
                ans=nodes[v].dist-1;
                break;
            }
        }
        move--;
    }
    cout<<ans<<endl;
}