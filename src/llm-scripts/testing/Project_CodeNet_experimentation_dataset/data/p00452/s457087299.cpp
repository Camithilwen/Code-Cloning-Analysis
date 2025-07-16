#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    for(;;){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        vector<int> ns(n+1);
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }
        ns[n]=0;
        vector<int> ntwos;
        for(int i=0;i<n+1;i++){
            for(int j=i;j<n+1;j++){
                ntwos.push_back(ns[i]+ns[j]);
            }
        }
        sort(ntwos.begin(),ntwos.end());
        int ma=0;
        for(int i=0;i<ntwos.size();i++){
            vector<int>::iterator it;
            if((it=upper_bound(ntwos.begin(),ntwos.end(),m-ntwos[i]))!=ntwos.begin()){
                ma=max(ma,ntwos[i]+*(it-1));
            }
        }
        printf("%d\n",ma);
    }
}