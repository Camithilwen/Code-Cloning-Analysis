#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007
#define rev(v) reverse(v.begin(), v.end());

bool comp(int a, int b){
    return (a<b);
}

int main(){
    int n; cin >> n;
    int a, b;
    if(n==1) cout << "Hello World";
    else{
        cin >> a >> b;
        cout << a+b;
    }
    cout << endl;
    return 0;
}