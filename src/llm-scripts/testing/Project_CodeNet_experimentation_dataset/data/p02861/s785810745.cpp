#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x[n];
    double y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    vector<int>v(n);
    for(int i=0;i<n;i++)v[i] = i;
    double summ = 0.0;
    double cnt = 0;
    do{
        cnt+=1.0;
        for(int i=0;i<n-1;i++){
            summ += sqrt((x[v[i]]-x[v[i+1]])*(x[v[i]]-x[v[i+1]]) + (y[v[i]]-y[v[i+1]])*(y[v[i]]-y[v[i+1]]));
        }
    }while(next_permutation(v.begin(),v.end()));

    printf("%.10lf", summ/cnt);
}