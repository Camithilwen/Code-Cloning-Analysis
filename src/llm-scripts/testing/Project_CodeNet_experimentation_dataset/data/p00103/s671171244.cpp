#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>
#include <functional>
#include <queue>
#include <cmath>
#include <set>

#define rep(i,j,k) for(int i=j;i<k;i++)
#define drep(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define Sort(x) sort((x).begin(),(x).end())
#define fi first
#define se second
#define vi vector<int>
#define INF 1000000000
#define MOD 1000000009
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;

int main() {
    int n;
    cin>>n;
    rep(i,0,n){
        int out=0;
        int score=0;
        int runner=0;
        string s;
        while(out!=3){
            cin>>s;
            if(s=="HIT"){
                if(runner==3)score++;
                else runner++;
            }else if(s=="OUT"){
                out++;
            }else{
                score+=runner+1;
                runner=0;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}


