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


int main()
{
int n;cin>>n;
int ans =0;

int i = 0;
while(i*i<=n)
{
    i++;
}
cout<<(i-1)*(i-1)<<endl;
 return 0;
}
