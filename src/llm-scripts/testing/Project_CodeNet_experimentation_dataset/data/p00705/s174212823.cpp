#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;

int main(){
    int n,q;
    while(cin>>n>>q){
        if(n==0 && q==0)break;
        int date[200];
        rep(i,200)date[i]=0;
        
        rep(i,n){
            int m;
            cin>>m;
            rep(j,m){
                int a;
                cin>>a;
                date[a]++;
            }
        }
        int maxi=-1;
        int day=-1;
        for(int i=1;i<100;i++){
            if(maxi<date[i]){
                day=i;
                maxi=date[i];
            }
        }
        if(maxi>=q)cout<<day<<endl;
        else cout<<"0"<<endl;
    }

    
    return 0;
}