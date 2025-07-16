#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double per(double n){
    if(n == 1) return n;
    return n*per(n-1);
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>>p(n);
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    double ans = 0;

    sort(p.begin(), p.end());

    do{
        for(int i=0;i<n;i++){
            if(i){
                ans += sqrt((p[i].first-p[i-1].first)*(p[i].first-p[i-1].first)+(p[i].second-p[i-1].second)*(p[i].second-p[i-1].second));
            }
        }
    }while(next_permutation(p.begin(), p.end()));

    ans /= per((double)n);
    printf("%.9lf\n", ans);

}