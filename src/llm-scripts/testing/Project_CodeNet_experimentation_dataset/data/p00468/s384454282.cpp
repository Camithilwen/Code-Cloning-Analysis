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
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;


int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        
        int data[600][600]={};
        rep(i,600){
            rep(j,600){
                if(i==j){
                    data[i][j]=0;
                }
                else{
                    data[i][j]=INF;
                }
            }
        }
        
        rep(i,m){
            int a,b;
            cin>>a>>b;
            a--;b--;
            data[a][b]=1;
            data[b][a]=1;
        }
        
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    data[i][j]=min(data[i][j],data[i][k]+data[k][j]);
                }
            }
        }
        int c=0;
        for(int i=1;i<n;i++){
            if(data[0][i]<=2)
                c++;
        }
        cout<<c<<endl;
    }
    return 0;
    
}