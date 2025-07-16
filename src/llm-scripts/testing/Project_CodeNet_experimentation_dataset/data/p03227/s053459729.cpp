#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
    string S;
  cin>>S;
    int a=S.size();
    if(a==2){
        cout<<S<<endl;
    }
    else{
        cout<<S[2]<<S[1]<<S[0]<<endl;
    }
}
