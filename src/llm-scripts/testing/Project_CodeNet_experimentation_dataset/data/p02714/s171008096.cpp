#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){

  ll n;cin >> n;

    string s;   cin >> s;
    ll r=0,g=0,b=0;

    for(int i=0;i<n;i++){
        if(s.at(i) == 'R')r++;
        if(s.at(i) == 'G')g++;
        if(s.at(i) == 'B')b++;
    }

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int k = j+(j-i);
            if(k>=n)break;
            if(s.at(i) != s.at(j) && s.at(j) != s.at(k) && s.at(k) != s.at(i))cnt++;
        }


    }
    cout << r*g*b - cnt << endl;
}
       
