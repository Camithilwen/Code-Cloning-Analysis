//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    vector<lint> zero(60);
    vector<lint> one(60);
    
    int n;cin>>n;
    lint x,tmp,ans=0;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<60;j++){
            tmp=x%2;
            if(tmp==0)zero[j]++;
            else one[j]++;
            x/=2;
        }
    }
    const int mod=1000000007;
    tmp=1;
    for(int i=0;i<60;i++){
        ans+=(zero[i]*one[i]%mod)*tmp;
        ans%=mod;
        tmp=tmp*2%mod;
    }
    cout<<ans<<endl;
}
