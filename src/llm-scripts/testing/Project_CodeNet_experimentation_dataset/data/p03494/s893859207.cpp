#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000007
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);

ll n ;
cin>>n;


ll arr[n];
for(ll index = 0 ;index < n;index++)
{
    cin>>arr[index];
    if(arr[index]%2)
    {
        cout<<0<<endl;
        return 0;
    }
}


int ans =INT_MAX;

for(ll index =0;index <n;index++)
{
    int div = 2;
    int curr=0;
    while(arr[index]%div==0)
    {
        curr++;
        div*=2;
    }
    ans =min(ans,curr);
}

cout<<ans<<endl;
 return 0;
}
