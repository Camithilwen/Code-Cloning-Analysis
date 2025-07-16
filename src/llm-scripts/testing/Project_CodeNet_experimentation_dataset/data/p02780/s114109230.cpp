#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<double> p(200000);
    for(int i=0; i<n; i++) cin >> p[i];

    vector<int> sigma(1000);
    sigma[0] = 1;
    for(int i=1; i<1000; i++){
        sigma[i] = sigma[i-1]+(i+1);
    }
    for(int i=0; i<n; i++){
        p[i] = sigma[p[i]-1] / p[i];
    }
    double MAX = 0; 
    double tmp = 0; 
    for(int i=0; i<k; i++) tmp += p[i];
    MAX = tmp;
    for(int i=1; i<=n-k; i++){
        tmp = tmp - p[i-1] + p[i+k-1];
        if(tmp > MAX){
            MAX = tmp; 
        }
    }
    printf("%.12f\n", MAX);
    return 0;
}