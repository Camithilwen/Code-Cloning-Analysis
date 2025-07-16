#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

unsigned int factorial(unsigned int n){
    if (n==0) return 1;
    else return n*factorial(n-1);
}

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> xy(n);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>xy[i].first>>xy[i].second;
        a[i]=i;
    }

    double l_sum=0;

    do{
        for(int i=0;i<n-1;i++){
            l_sum+=sqrt(pow(xy[a[i]].first-xy[a[i+1]].first,2)+pow(xy[a[i]].second-xy[a[i+1]].second,2));
        }
    }while(next_permutation(a.begin(),a.end()));

    cout<<fixed<<setprecision(10)<<l_sum/(double) factorial(n)<<endl;

    return 0;
}