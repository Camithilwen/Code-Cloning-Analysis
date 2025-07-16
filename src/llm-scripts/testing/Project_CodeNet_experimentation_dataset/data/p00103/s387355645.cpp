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
#define all(in) in.begin(), in.end()
#define MAX 9999999
using namespace std;
typedef struct{
    int count;
    string s="OUT";
}OUT;
typedef struct{
    int count;
    string s="HOMERUN";
}HOME;
typedef struct{
    int count;
    string s="HIT";
}HIT;
typedef struct{
    int count;
}RUN;
typedef pair<int, int> pii;
int main(){
    int n; cin>>n;
    int ans=0;
    OUT out; HOME home; HIT hit; RUN run;
    out.count=0; home.count=0; hit.count=0; run.count=0;
    string temp;
    while(cin>>temp){
        if(temp==home.s){
            ans+=run.count+1;
            run.count=0;
        }
        if(temp==hit.s){
            run.count++;
            if(run.count>3){ans++; run.count-=1;}
        }
    if(temp==out.s){
        out.count++;
        if(out.count%3==0){cout<<ans<<endl;ans=0;run.count=0;}
        if(out.count==(n*3))return 0;
    }
    }
}