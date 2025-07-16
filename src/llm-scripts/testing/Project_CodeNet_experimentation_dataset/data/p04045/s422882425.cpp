#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs              v.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii                pair<int,int>
#define ll                long long
#define ull              unsigned long long
#define pb              push_back
#define mpp          make_pair
#define Okay         0
#define pi               3.14159

static ll int inf = 1e9;
const int cont = 10e5+10;
using namespace std;
bool ar[10];
int n,m;

bool wrong(int n){
    while(n>0){
        if(ar[n%10])return true;
        n/=10;
    }
    return false;
}


void solve(){
    int m,n;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int a;
        cin>>a;
        ar[a] = 1;
    }

   while(wrong(n)){
    n++;
   }
   cout<<n<<endl;
}

int main(){

solve();

	return Okay;
}
