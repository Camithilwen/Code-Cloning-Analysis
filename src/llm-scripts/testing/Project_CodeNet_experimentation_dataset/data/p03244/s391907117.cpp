#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int, int>> v1(1e5+1);
    vector<pair<int, int>> v2(1e5+1);
    for(int i=0; i<n; i++){
        int in;
        cin>> in;
        if(i % 2 == 0){
            v1[in].first++;
            v1[in].second = in;
        }else{
            v2[in].first++;
            v2[in].second = in;            
        }
    }
    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    sort(v2.begin(), v2.end(), greater<pair<int, int>>());

    int cnt;
    if(v1[0].second != v2[0].second){
        cnt = v1[0].first + v2[0].first;
    }else{
        cnt = max(v1[0].first + v2[1].first, v1[1].first + v2[0].first);
    }

    cout<< n - cnt <<endl;
    return 0;
}