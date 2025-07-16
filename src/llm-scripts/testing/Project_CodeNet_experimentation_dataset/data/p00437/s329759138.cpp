#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

int flag[301] = {0};

int main(void){
    while(1){
        for(int i = 1;i <= 300;i++){
            flag[i] = 2;
        }
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0 && b == 0 && c == 0) break;
        vector < pair<pair<int,int> ,pair<int,int> > > v;
        pair<pair<int,int>,pair<int,int> > input;
        int n; scanf("%d",&n);
        for(int i = 0;i < n;i++){
            int x,y,z,w; scanf("%d%d%d%d",&x,&y,&z,&w);
            input.first.first = w;
            input.first.second = x;
            input.second.first = y;
            input.second.second = z;
            v.push_back(input);
        }
        sort(v.begin(),v.end(),greater <pair< pair<int,int>,pair<int,int> > >());
        for(int i = 0;i < n;i++){
            if(v[i].first.first == 1){
                flag[v[i].first.second] = 1;
                flag[v[i].second.first] = 1;
                flag[v[i].second.second] = 1;
            }
            else{
                if(flag[v[i].first.second] == 1 &&
                   flag[v[i].second.first] == 1 &&
                   flag[v[i].second.second] == 2){
                    flag[v[i].second.second] = 0;
                }

                if(flag[v[i].first.second] == 1 &&
                   flag[v[i].second.first] == 2 &&
                   flag[v[i].second.second] == 1){
                    flag[v[i].second.first] = 0;
                }

                if(flag[v[i].first.second] == 2 &&
                   flag[v[i].second.first] == 1 &&
                   flag[v[i].second.second] == 1){
                    flag[v[i].first.second] = 0;
                }
            }
        }
        for(int i = 1;i <= a+b+c;i++){
            printf("%d\n",flag[i]);
        }

    }
    return 0;
}