//! 尺卂乃卂.卂ﾌ乇乇ㄒ
#include<bits/stdc++.h>
using namespace std;

#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vector<int>>
#define mii             map<int,int>
#define mip             map<pair<int,int>,int>
#define mic             map<char,int> 
#define all(v)          v.begin(),v.end()  
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define itr(v)          for(auto it:v)
#define show(arr,n)     for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"\n";
#define fi(i,n)         for(int i=0;i<n;i++)
#define fd(i,n)         for(int i=n-1;i>=0;i--)
#define fir(i,a,b)      for(int i=a;i<b;i++)
#define fin(s)          freopen(s,"r",stdin);  
#define fout(s)         freopen(s,"w",stdout);
#define MAXZ            200005
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int expo(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return a;
    int val=(expo(a,b/2,m)*expo(a,b/2,m))%m;
    if(b & 1) return (val*a)%m;
    else return val;
}
int mmi(int a,int m){
    return expo(a,m-2,m);
}
bool cmp(pii a,pii b){
    int c1=a.first-a.second;
    int c2=b.first-b.second;
    if(c1*c2>=0){
        if(c1>=0 && c2>=0){
            return a.second<b.second;
        }
        else{
            return a.first>b.first;
        }

    }
    else{
        if(c1>0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
 string a[2000001];
int32_t main()
{
    FIO
    int n; cin>>n;
    fi(i,n) cin>>a[i];
    vector<pii> v;
    int uop=0,ucp=0;
    fi(i,n) {
        int op=0,cp=0;
        int count=0;
        for(int j=0;j<a[i].length();j++){
            if(a[i][j]=='('){
                count++;
            }
            else{
                if(count<=0) {
                    cp++;
                }
                else count--;
            }
        }
        op+=count;
        pii p1(op,cp);
        if(op==0 || cp==0){
            uop+=op;
            ucp+=cp;
        }
        else v.pb(p1);
        // cout<<a[i]<<" "<<op<<" "<<cp<<"\n";
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1;
    int op=uop;
    for(int i=0;i<v.size();i++){
        // cout<<v[i].first<<" "<<v[i].second<<"\n";
        op=op-v[i].second;
        if(op<0) {
            ans=0;
            break;
        }
        op+=v[i].first;
    }
    op-=ucp;
    if(op==0 && ans){
        cout<<"Yes\n";
    }
    else cout<<"No\n";

}