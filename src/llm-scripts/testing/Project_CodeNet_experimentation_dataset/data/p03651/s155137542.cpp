# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int arr[100005];
int n,k,x;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);

} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    bool u=false;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i==1) x=arr[1];
        else x=gcd(x,arr[i]);
        if(arr[i]==k){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
        if(arr[i]>k) u=true;
    }
    if(!u){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if(k%x==0){
        cout<<"POSSIBLE"<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;

}