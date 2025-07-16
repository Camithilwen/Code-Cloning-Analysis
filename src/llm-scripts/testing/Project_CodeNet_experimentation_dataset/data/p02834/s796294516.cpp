#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N,u,v;
    cin >> N >> u >> v;
    vector<vector<int>> A(N);
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    queue<int> q1;
    q1.push(u-1);
    vector<int> D1(N,-1);
    D1[u-1]=0;
    while(q1.size()){
        int f=q1.front();
        q1.pop();
        for(int a:A[f]){
            if(D1[a]==-1){
                D1[a]=D1[f]+1;
                q1.push(a);
            }
        }
    }
    queue<int>q2;
    q2.push(v-1);
    vector<int>D2(N,-1);
    D2[v-1]=0;
    while(q2.size()){
        int f=q2.front();
        q2.pop();
        for(int a:A[f]){
            if(D2[a]==-1){
                D2[a]=D2[f]+1;
                q2.push(a);
            }
        }
    }
    
    vector<int> NG(N,0);
    int M=0,Mi=-1;
    for(int i=0;i<N;i++){
        NG[i]=(D2[i]-D1[i]<0);
        if((!NG[i]) && M<D2[i]){
            M=D2[i];
            Mi=i;
        }
    }
    if(NG[u-1]){
        cout << 0;
        return 0;
    }
    cout << D1[Mi]+(D2[Mi]-D1[Mi])-1 << "\n";
}