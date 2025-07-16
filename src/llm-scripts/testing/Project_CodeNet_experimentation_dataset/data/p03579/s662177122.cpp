#include <bits/stdc++.h>
using namespace std;
//#define INF 1145141919810893364
#define REP(i,n) for(int i=0;i<(n);++i)

std::vector<int> bipartite(std::vector<std::pair<int,int>> edge){
    int M = edge.size();
    if(M==0)return {};
    int N = 0;
    for(int i=0;i<M;i++){
        N=std::max(N,edge[i].first+1);
        N=std::max(N,edge[i].second+1);
    }
    std::vector<int> R(N,-1);
    std::vector<int> S(0);
    std::vector<std::vector<int>> es(N,std::vector<int>(0));
    for(int i=0;i<M;i++){
        es[edge[i].first].push_back(edge[i].second);
        es[edge[i].second].push_back(edge[i].first);
    }
    std::queue<int> Q;
    std::vector<bool> visited(N,false);
    for(int j=0;j<N;j++){
        if(visited[j])continue;
        Q.push(j);
        R[j]=0;
        visited[j]=true;
        while(!Q.empty()){
            int q=Q.front();
            Q.pop();
            visited[q]=true;
            for(int i=0;i<es[q].size();i++){
                if(R[es[q][i]]==R[q]){
                    return S;
                }
                if(visited[es[q][i]])continue;
                Q.push(es[q][i]);
                R[es[q][i]]=1-R[q];
            }
            
        }
    }
    return R;
}

signed main(void){
    long long N,M;
    int a,b;
    vector<int> A,B;
    cin >> N >> M;
    REP(i,M){
        cin >> a >> b;
        a--;b--;
        A.push_back(a);
        B.push_back(b);
    }
    vector<pair<int,int>> AB;
    REP(i,M){
        AB.push_back({A[i],B[i]});
        //cout << A[i] MM B[i] << endl;
    }
    
    vector<int> d=bipartite(AB);
    //vector<int> d(N,1);
    if(d.size()==0){
        cout << N*(N-1)/2 - M << endl;
        return 0;
    }
    //REP(i,N){cout << d[i] << " ";}cout << endl;
    long long x=0,y=0;
    REP(i,N){
        if(d[i]){
            x++;
        }else{
            y++;
        }
    }
    cout << x*y - M << endl;
    return 0;
}
