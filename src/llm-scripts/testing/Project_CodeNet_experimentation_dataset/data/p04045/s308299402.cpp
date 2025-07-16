#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define lint                     long long 
#define setbits(x)              __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define zlbits(x)               __builtin_clzll(x)
#define parsbits(x)             __builtin_parityll(x)
#define mem(a, b)               memset(a, (b), sizeof(a))
#define MOD                     1000000007
#define inf                     1e17 
#define neginf                  -1e17 
#define sp(x,y)                 fixed<<setprecision(x)<<y
#define testcase(t)             lint t; cin>>t; while(t--)
#define power(a,b)              (double)pow((double)a,(double)b)
#define FOR(i,n)                for(lint i=0;i<n;i++)
#define gcd(a,b)                __gcd(a,b)
#define PI                      3.1415926535
#define pb                      push_back
#define ss                      second
#define ff                      first
#define umap                    unordered_map           
#define ummap                   unordered_multimap
#define uset                    unordered_set
#define umset                   unordered_multiset

             
typedef unsigned long long   ull;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
         
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //  #ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\input1.txt", "r", stdin);
   /// freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\output1.txt", "w", stdout);
   // #endif
}

lint me(lint x, lint y, lint p)  
{  
    lint res = 1;     
     
    x = x % p; 
           
    if (x == 0) return 0; 
          
    while (y > 0)  
    {  
                
        if (y & 1)  
        res = (res*x) % p;  
          
                  
        y = y>>1;  
        x = (x*x) % p;  
    }  
    return res;  
}

    /*---------------------------SOLUTION---------------------------------*/

void solve()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lint n,k;
    cin>>n>>k;
    lint arr[10]={0};
    for(lint i=0;i<k;i++)
    {
        lint u;
        cin>>u;
        arr[u]=1;
    }
    for(lint i=n;i<=100000;i++)
    {
        lint x=i;
        lint flg=0;
        while(x>0)
        {
            lint p=x%10;
            x=x/10;
            if(arr[p]==1)
                flg=1;
        }
        if(flg==0)
        {
            cout<<i<<endl;
            return;
        }
    }

}


int main()
{
    c_p_c();
    lint flg99=0;
    if(flg99==1)
    {
        testcase(t)
        {
             solve();
        }
    }
    else
    {
        solve();
    }
    return 0;
            
}
                
            
                

                

                

