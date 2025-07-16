#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int a,b;
    cin>>a>>b;
    vector<int> s(3);
    s[0]=a+a-1;
    s[1]=b+b-1;
    s[2]=a+b;
    int ans=0;
    rep(i,3){
        ans=max(ans,s[i]);
    }
    cout<<ans<<endl;
}