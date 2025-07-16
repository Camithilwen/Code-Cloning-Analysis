#include<bits/stdc++.h>
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector<long long int> adj[200001];
bool vis[200001];
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7

#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll t;cin>>t;while(t--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));

string cmp(string a,string b){
    int n=a.size(),m=b.size();
    if(n>m) return(a);
    if(m>n) return(b);
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        if((a[i]-'0')>(b[i]-'0')) return(a);
        else return(b);
    }
    return(a);
}
string ss="0123456789";
int main(){
    IO
    int n,m;
    cin>>n>>m;
    int mat[]={0,2,5,5,4,5,6,3,7,6};
    int arr[m];
    for(int i=0;i<m;i++) cin>>arr[i];
    sort(arr,arr+m);
    map<int,string> mp;
    //for(int i=0;i<=n;i++) mp[i]="";
    /*
    for(int i=0;i<m;i++){
        string s=mp[mat[arr[i]]];
        string p="";
        p+=ss[arr[i]];
        //cout<<s<<" "<<p<<endl;
        mp[mat[arr[i]]]=cmp(p,s);
    }
    */

    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i-mat[arr[j]]<0) continue;
            string s=mp[i-mat[arr[j]]];
            string p=mp[i];
            if(s=="" && i!=mat[arr[j]]) continue;
            s+=ss[arr[j]];
            sort(s.rbegin(),s.rend());
            mp[i]=cmp(s,p);
            /*
            cout<<"i is "<< i<<" ";
            cout<<"j is "<<j<<" ";
            cout<<" mat[arr["<<j<<"]] is "<<mat[arr[j]]<<" ";
            cout<<"mp["<<i<<"] is "<<mp[i]<<"\n";
            */
        }

    }
    /*
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<mp[i]<<"\n";
    }
    */
    cout<<mp[n];
    return(0);
}