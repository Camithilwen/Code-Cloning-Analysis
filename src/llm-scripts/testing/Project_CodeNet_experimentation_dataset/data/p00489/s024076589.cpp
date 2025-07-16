#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#include<map>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
using namespace std;
typedef pair<int, int> pii;
#define MAX 99999999
int main(){
    int n;
    cin>>n;
    vi v(n+1,0);
    rep(i,n*(n-1)/2){
        pii a,b;
        cin>>a.first>>b.first;cin>>a.second>>b.second;
        if(a.second==b.second){v[a.first]++; v[b.first]++;}
        else{
            a.second>b.second ? v[a.first]+=3:v[b.first]+=3;
        }
    }
        vi hoge;
        rep(i,n)hoge.push_back(v[i+1]);
        sort(hoge.begin(),hoge.end(),greater<int>());
        rep(i,n){
            for(int j=0;j<n;j++){
                if(hoge[j]==v[i+1]){cout<<j+1<<endl; break;}
            }
        }
    }