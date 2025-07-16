#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool prime[MAX];
int prime_numbers[9999999],pos;
void sieve()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<=MAX; i+=2)
        prime[i]=1;
    int root = sqrt(MAX);
    for(int i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    prime_numbers[pos++]=2;
    for(int i=3; i<MAX; i+=2)
        if(prime[i]==0)
            prime_numbers[pos++]=i;
}
map<int,int>mp;
void recur(int pos,int sum,int taken,vector<int>v)
{
    if(pos>=20)
        return;
    if(taken==5)
    {
        if(sum==67)
        {
           for(int i=0;i<5;i++)
            cout<<v[i]<<" ";
           cout<<endl;
        }

        mp[sum]++;
        return ;
    }
    v.push_back(prime_numbers[pos]);
    recur(pos+1,sum+prime_numbers[pos],taken+1,v);
    v.pop_back();
    recur(pos+1,sum,taken,v);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    sieve();
 //   for(int i=0; prime_numbers[i]<55555; i++)
    //    cout<<prime_numbers[i]<<" "<<mp[prime_numbers[i]]<<endl;
    int n;
    cin>>n;
    for(int i=0;i<pos;i++){
        if(prime_numbers[i]%10==7){
            cout<<prime_numbers[i]<<" ";
         n--;
        }
        if(n==0)
            break;
    }




    return 0;
}
