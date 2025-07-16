#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
double dist(int x1,int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
    int N; cin>>N;
    vi x(N),y(N);
    for (int i = 0; i < N; i++){
        cin>>x[i]>>y[i];
    }
    vi perm(N);
    for (int i = 0; i < N; i++){
        perm[i]=i;
    }
    double sum=0;
    do{
        for (int i = 0; i < N-1; i++){
            sum+=dist(x[perm[i]],y[perm[i]],x[perm[i+1]],y[perm[i+1]]);
        }
    }while(next_permutation(perm.begin(),perm.end()));
    int fact=1;
    for (int i = 1; i <= N; i++){
        fact*=i;
    }
    printf("%.7f\n",sum/(double)fact);
}