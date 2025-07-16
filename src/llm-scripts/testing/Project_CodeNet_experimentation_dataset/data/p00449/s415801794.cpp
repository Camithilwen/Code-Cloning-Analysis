#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#define PAIR pair<long long,int>
using namespace std;

class island{
public:
    vector<PAIR> road;
    void add(int goal,int much){
        road.push_back(PAIR(much,goal));
    }
};
long long func(vector<island>&,int,int);
int main(){
    int n,m;
    while(cin>>n>>m&&n){
        vector<island> map(n+1);
        for(int i=0;i<m;++i){
            int type;
            cin>>type;
            if(type==1) {
                int a,b,much;
                cin>>a>>b>>much;
                map[a].add(b,much);
                map[b].add(a,much);
            }else{
                int s,g;
                cin>>s>>g;
                cout<<func(map,s,g)<<endl;
            }
        }
    }
    return 0;
}

long long func(vector<island>& map,int s,int g){
    vector<long long> much(map.size()+1,-1);
    priority_queue<PAIR,vector<PAIR>,greater<PAIR> > que;
    que.push(PAIR(0,s));
    much[s]=0;
    while(!que.empty()){
        PAIR dpair = que.top();
        que.pop();
        long long time = dpair.first;
        int np = dpair.second;
        if(much[np]!=time){
            continue;
        }
        for(vector<PAIR>::iterator itr = map[np].road.begin();itr!=map[np].road.end();++itr){
            long long ntime = time + itr->first;
            int ng = itr->second;
            if(much[ng]==-1||much[ng]>ntime){
                much[ng]=ntime;
                que.push(PAIR(ntime,ng));
            }
        }
    }
    return much[g];
}
