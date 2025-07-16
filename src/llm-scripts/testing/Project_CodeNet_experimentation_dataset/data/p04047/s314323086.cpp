#include <bits/stdc++.h>
using namespace std;
 

 
int main() {

    int64_t n;
    cin>>n;


    vector<int> L(2*n);
    for(int i=0;i<2*n;i++){
        cin>>L.at(i);
    }

    sort(L.begin(),L.end());

    int64_t sum=0;
    for(int i=0;i<2*n;i++){
        if(i%2==1)
            sum+=min(L.at(i),L.at(i-1));
    }

    cout<<sum<<endl;

 	return 0;
}