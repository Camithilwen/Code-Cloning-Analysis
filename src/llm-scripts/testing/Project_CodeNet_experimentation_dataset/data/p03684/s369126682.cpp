#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,pair<long long,long long>>> edges;
const long long MAXN = 2e5+5;
long long par[MAXN];
long long sz[MAXN];
pair<pair<long long,long long>,long long> arr[MAXN];
pair<pair<long long,long long>,long long> arr2[MAXN];
long long getpar(long long a){
    if(par[a] == a){
        return a;
    }
    return par[a] = getpar(par[a]);
}
void merge(long long a,long long b){
    a = getpar(a);
    b = getpar(b);
    if(a==b){
        return;
    }
    if(sz[b]>sz[a]){
        swap(a,b);
    }
    sz[a]+=sz[b];
    par[b] = a;
}
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i].first.first>>arr[i].first.second;
        arr2[i].first.first = arr[i].first.second;
        arr2[i].first.second = arr[i].first.first;
        arr[i].second = i;
        arr2[i].second = i;
    }
    sort(arr+1,arr+n+1);
    sort(arr2+1,arr2+n+1);
    for(long long i=1;i<n;i++){
        edges.push_back(make_pair(arr[i+1].first.first-arr[i].first.first,make_pair(arr[i].second,arr[i+1].second)));
        edges.push_back(make_pair(arr2[i+1].first.first-arr2[i].first.first,make_pair(arr2[i].second,arr2[i+1].second)));
    }
    sort(edges.begin(),edges.end());
    for(long long i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    long long ans = 0;
    for(auto x:edges){
        long long w = x.first;
        long long from = x.second.first;
        long long to = x.second.second;
        if(getpar(from)== getpar(to)){
            continue;
        }
        merge(from,to);
        ans+=w;
    }
    cout<<ans<<endl;
}
