#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    int n;
    string a,b,c;
    cin >> n >> a >> b >> c;
    int cnt=0;
    rep(i,n){
        char aa=a.at(i);
        char bb=b.at(i);
        char cc=c.at(i);
        if(aa!=bb && aa!=cc && bb!=cc)cnt+=2;
        else if(aa==bb && aa!=cc)cnt++;
        else if(aa==cc && aa!=bb)cnt++;
        else if(bb==cc && bb!=aa)cnt++;
    }
    cout << cnt << endl;
}