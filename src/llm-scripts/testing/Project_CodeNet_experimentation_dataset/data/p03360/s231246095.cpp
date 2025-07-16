#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int solve(int k, vi& xs){
    sort(xs.begin(), xs.end()); //ordena o vector

    //xs.back() --> Returns a reference to the last element in the vector
    xs.back() *= (1<<k); // shiftar 1 vez pra esquerda eh multiplicar por 2

    return accumulate(xs.begin(), xs.end(), 0);
}

int main(){
    vi xs(3);

    for(int i=0;i<3;i++)
        cin>>xs[i];

    int k;

    cin>>k;

    auto ans = solve(k, xs);

    cout<<ans<<'\n'<<endl;

    return 0;
}