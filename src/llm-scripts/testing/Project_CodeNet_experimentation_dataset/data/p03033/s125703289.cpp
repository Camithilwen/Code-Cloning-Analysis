#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,q; cin >> n >> q;
    vector<T> rw(n);
    rep(i,n){
        int a,b,c; cin >> a >> b >> c;
        rw[i]=T(c,a,b);
    }
    sort(all(rw));
    map<int,int> index;

    vector<int> t(q+2);
    t[0]=-INF;
    t[q+1]=INF;
    rep(i,q){
        cin >> t[i+1];
        index[t[i+1]]=i;
    }

    vector<int> ans(q,-1);

    rep(i,n){
        int a,b,c;
        tie(a,b,c)=rw[i];
        b-=a;
        c=c-a;
        int left,right;
        int l,r;
        l=0;
        r=t.size()-1;
        while(r!=l){
            int cen=(r+l)/2;
            if(t[cen]>=b) r=cen;
            else l=cen+1;
        }
        left=l;
        l=0;
        r=t.size()-1;
        while(r!=l){
            int cen=(r+l)/2;
            if(t[cen]>=c) r=cen;
            else l=cen+1;
        }
        right=l-1;
        for(int j=left; j<=right; j++){
            ans[index[t[j]]]=a;
        }
        while(right-left+1>0){
            t.erase(t.begin()+left);
            right--;
        }
    }

    rep(i,q) cout << ans[i] << endl;
    return 0;
}
