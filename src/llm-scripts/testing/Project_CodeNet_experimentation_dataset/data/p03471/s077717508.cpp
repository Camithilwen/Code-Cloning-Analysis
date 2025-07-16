#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int n,y;cin>>n>>y;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int k=(y-10000*i-5000*j)/1000;
            if(i+j+k==n && 0<=k && k<=n){
                cout<<i<<" "<<j<<" "<<k<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
}
