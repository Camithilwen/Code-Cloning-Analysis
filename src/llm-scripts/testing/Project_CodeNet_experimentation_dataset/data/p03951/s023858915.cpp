#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s>>t;
    for(int i=n;i>=1;i--){
        if(t.substr(0,i)==s.substr(n-i,i)){
            cout<<2*n-i<<endl;
            return 0;
            
        }
    }
    cout<<2*n<<endl;
  return 0;
}