#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,time,ans=0,flag=0;
    cin>>n>>time;
    int s,e;
    cin>>s;
    e=s+time;
    for(int i =1;i <n;i++){
        int inter;
        cin>>inter;


        if(inter <=e){
            e = inter + time;
           // cout<<"in between "<<e<<endl;
            flag=0;
        }
        else{
            ans = ans + (e-s);
            //cout<<"broken"<<" "<<ans<<endl;
            flag=1;
            s = inter;
            e = inter  + time;
        }

    }
    ans = ans + e-s ;
    cout<<ans<<endl;















}


















