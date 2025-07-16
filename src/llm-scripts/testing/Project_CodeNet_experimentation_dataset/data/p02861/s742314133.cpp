#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define BIL ((ll)1e9)
#define MOD ((ll)1e9+7)
#define INF (1LL<<60)           //1LL<<63でオーバーフロー
#define inf (1<<29)             //1<<29でオーバーフロー

int main(int argc,char* argv[]){
    int n;
    cin >> n;

    vector<pair<double,double>> root(n);
    for(auto &x:root){
        cin >> x.first >> x.second;
    }

    vector<vector<double>> dist(n,vector<double>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dist[i][j]!=-1)continue;
            dist[i][j]=sqrt((root[i].first-root[j].first)*(root[i].first-root[j].first)+(root[i].second-root[j].second)*(root[i].second-root[j].second));
        }
    }

    vector<int> perm(n);
    for(int i=0;i<n;i++){
        perm[i]=i;
    }

    double sumdist=0;
    int count=0;
    do{
        for(int i=0;i<n-1;i++){
            int nowbeg=perm[i],nowend=perm[i+1];
            double nowdist=max(dist[nowbeg][nowend],dist[nowend][nowbeg]);
            sumdist+=nowdist;
        }
        count++;
    }while(next_permutation(perm.begin(),perm.end()));

    printf("%.7lf",sumdist/count);

    return 0;
}
