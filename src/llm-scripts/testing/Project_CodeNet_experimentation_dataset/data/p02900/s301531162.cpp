#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;
 
template <class type> void printVector(vector<type> vec){
    stringstream ss;
    for(ll i=0;i<vec.size();i++)
    {
        ss<<vec[i]<<" ";
        if(i!=vec.size()-1)ss<<" ";
    }
    cout<<ss.str()<<endl;
}


//vector<pair<ll,ll> > prime_factorize(ll n) {
    //vector<pair<ll,ll>> res;
    //for (long long p = 2; p * p <= n; ++p) {
        //if (n % p != 0) continue;
        //int num = 0;
        //while (n % p == 0) { ++num; n /= p; }
        //res.push_back(make_pair(p, num));
    //}
    //if (n != 1) res.push_back(make_pair(n, 1));
    //return res;
//}
 
vector<pair<ll,ll>> prime_factorize(ll num)
{
    vector<pair<ll,ll>> res;
    for(ll p=2;p*p<=num;++p){
        if(num%p!=0)continue;
        ll ex=0;
        while(num%p==0){
            ++ex;
            num/=p;
        }
        res.push_back({p,ex});
    }
    if(num!=1)res.push_back({num,1});
    return res;
}


ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

void solve(){
    ll A,B;
    cin>>A>>B;
    ll gcd=GCD(A,B);
    ll res=prime_factorize(gcd).size()+1;
    cout<<res;
}
 
int main(){
    solve();
    return 0;
}